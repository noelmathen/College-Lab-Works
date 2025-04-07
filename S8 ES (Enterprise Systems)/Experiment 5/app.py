from flask import Flask, render_template, request, redirect, url_for, session, flash
import pandas as pd
import os

app = Flask(__name__)
app.secret_key = '1234'
# ------------------------------------------
# Helper functions
# ------------------------------------------
def initialize_inventory_csv(filename="inventory.csv"):
    if not os.path.isfile(filename):
        df = pd.DataFrame(columns=["Product ID",
                                   "Product Name",
                                   "Category",
                                   "Price",
                                   "Stock",
                                   "Total Sales"])
        df.to_csv(filename, index=False)
        print(f"{filename} created with header columns.")
    else:
        print(f"{filename} already exists. Continuing...")

def load_inventory(filename="inventory.csv"):
    return pd.read_csv(filename)

def save_inventory(df, filename="inventory.csv"):
    df.to_csv(filename, index=False)

# Ensure inventory.csv exists when app starts
initialize_inventory_csv()

# ------------------------------------------
# Routes for web interface
# ------------------------------------------
@app.route('/')
def home():
    if not session.get('logged_in'):
        return redirect(url_for('login'))
    return render_template('index.html')

# Hardcoded credentials
USERNAME = "admin"
PASSWORD = "admin123"

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        if request.form['username'] == USERNAME and request.form['password'] == PASSWORD:
            session['logged_in'] = True
            flash('Login successful!', 'success')
            return redirect(url_for('home'))
        else:
            flash('Invalid credentials.', 'danger')
    return render_template('login.html')


@app.route('/logout')
def logout():
    session.pop('logged_in', None)
    flash('You have been logged out.', 'info')
    return redirect(url_for('login'))


@app.route('/view_inventory')
def view_inventory():
    df = load_inventory()
    return render_template('view_inventory.html', inventory=df.to_dict('records'))

@app.route('/add_product', methods=['GET', 'POST'])
def add_product():
    if request.method == 'POST':
        df = load_inventory()
        
        product_id = request.form['product_id'].strip()
        
        # Check if Product ID already exists
        if product_id in df["Product ID"].astype(str).values:
            return render_template('add_product.html', error=f"Product ID {product_id} already exists!")
        
        try:
            price = float(request.form['price'])
            stock = int(request.form['stock'])
        except ValueError:
            return render_template('add_product.html', error="Invalid price or stock values.")
        
        # Create a new row
        new_row = {
            "Product ID": product_id,
            "Product Name": request.form['product_name'].strip(),
            "Category": request.form['category'].strip(),
            "Price": price,
            "Stock": stock,
            "Total Sales": 0
        }
        
        # Add the new row
        df = pd.concat([df, pd.DataFrame([new_row])], ignore_index=True)
        
        # Save the updated DataFrame
        save_inventory(df)
        
        return redirect(url_for('view_inventory'))
    
    return render_template('add_product.html')

@app.route('/update_product', methods=['GET', 'POST'])
def update_product():
    df = load_inventory()
    
    if request.method == 'POST':
        if 'product_id' in request.form:
            # First form submission - user selected a product
            product_id = request.form['product_id'].strip()
            if product_id not in df["Product ID"].astype(str).values:
                return render_template('update_product.html', products=df.to_dict('records'), 
                                       error=f"Product ID {product_id} not found.")
            
            product = df[df["Product ID"].astype(str) == product_id].to_dict('records')[0]
            return render_template('update_product_details.html', product=product)
        
        elif 'update_submit' in request.form:
            # Second form submission - updating the details
            product_id = request.form['update_product_id']
            row_index = df.index[df["Product ID"].astype(str) == product_id].tolist()[0]
            
            try:
                # Update values based on form data
                if 'product_name' in request.form:
                    df.at[row_index, "Product Name"] = request.form['product_name'].strip()
                if 'category' in request.form:
                    df.at[row_index, "Category"] = request.form['category'].strip()
                if 'price' in request.form:
                    df.at[row_index, "Price"] = float(request.form['price'])
                if 'stock' in request.form:
                    df.at[row_index, "Stock"] = int(request.form['stock'])
            except ValueError:
                product = df[df["Product ID"].astype(str) == product_id].to_dict('records')[0]
                return render_template('update_product_details.html', product=product, 
                                       error="Invalid numeric value entered.")
            
            save_inventory(df)
            return redirect(url_for('view_inventory'))
    
    return render_template('update_product.html', products=df.to_dict('records'))

@app.route('/record_sale', methods=['GET', 'POST'])
def record_sale():
    df = load_inventory()
    
    if request.method == 'POST':
        product_id = request.form['product_id'].strip()
        
        if product_id not in df["Product ID"].astype(str).values:
            return render_template('record_sale.html', products=df.to_dict('records'), 
                                   error=f"Product ID {product_id} not found.")
        
        try:
            quantity_sold = int(request.form['quantity'])
        except ValueError:
            return render_template('record_sale.html', products=df.to_dict('records'), 
                                   error="Invalid quantity entered.")
        
        # Locate the product row
        row_index = df.index[df["Product ID"].astype(str) == product_id].tolist()[0]
        current_stock = df.at[row_index, "Stock"]
        
        if quantity_sold <= 0:
            return render_template('record_sale.html', products=df.to_dict('records'),
                                   error="Quantity sold must be positive.")
        
        if current_stock < quantity_sold:
            return render_template('record_sale.html', products=df.to_dict('records'),
                                   error=f"Insufficient stock ({current_stock}) for product {product_id}.")
        
        # Deduct stock and update sales
        df.at[row_index, "Stock"] = current_stock - quantity_sold
        df.at[row_index, "Total Sales"] = df.at[row_index, "Total Sales"] + quantity_sold
        
        save_inventory(df)
        return redirect(url_for('view_inventory'))
    
    return render_template('record_sale.html', products=df.to_dict('records'))

@app.route('/recommend_restock')
def recommend_restock():
    df = load_inventory()
    threshold = 10  # Default threshold
    
    # Filter products where Stock < threshold
    to_restock = df[df["Stock"] < threshold]
    
    return render_template('recommend_restock.html', 
                           restock_items=to_restock.to_dict('records'),
                           threshold=threshold)

if __name__ == '__main__':
    initialize_inventory_csv()
    app.run(debug=True, host='0.0.0.0', port=5000)