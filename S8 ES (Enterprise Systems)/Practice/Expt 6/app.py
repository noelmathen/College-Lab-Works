from flask import Flask, render_template, request, redirect, url_for
import pandas as pd
import os

app = Flask(__name__)

# -----------------------------
# Helper functions
# -----------------------------
def initialize_inventory_csv(filename="inventory.csv"):
    if not os.path.isfile(filename):
        df = pd.DataFrame(columns=["Product ID", "Product Name", "Category", "Price", "Stock", "Total Sales"])
        df.to_csv(filename, index=False)
        print(f"{filename} created.")
    else:
        print(f"{filename} exists.")

def load_inventory(filename="inventory.csv"):
    return pd.read_csv(filename)

def save_inventory(df, filename="inventory.csv"):
    df.to_csv(filename, index=False)

# Ensure CSV exists on startup
initialize_inventory_csv()

# -----------------------------
# Routes
# -----------------------------
@app.route('/')
def home():
    return render_template('index.html')

@app.route('/view_inventory')
def view_inventory():
    df = load_inventory()
    return render_template('view_inventory.html', inventory=df.to_dict('records'))

@app.route('/add_product', methods=['GET', 'POST'])
def add_product():
    if request.method == 'POST':
        df = load_inventory()
        pid = request.form['product_id'].strip()
        if pid in df["Product ID"].astype(str).values:
            return render_template('add_product.html', error="Product ID already exists!")
        try:
            price = float(request.form['price'])
            stock = int(request.form['stock'])
        except ValueError:
            return render_template('add_product.html', error="Invalid price or stock")
        new_row = {
            "Product ID": pid,
            "Product Name": request.form['product_name'].strip(),
            "Category": request.form['category'].strip(),
            "Price": price,
            "Stock": stock,
            "Total Sales": 0
        }
        df = pd.concat([df, pd.DataFrame([new_row])], ignore_index=True)
        save_inventory(df)
        return redirect(url_for('view_inventory'))
    return render_template('add_product.html')

@app.route('/update_product', methods=['GET', 'POST'])
def update_product():
    df = load_inventory()
    if request.method == 'POST':
        if 'product_id' in request.form:
            pid = request.form['product_id'].strip()
            if pid not in df["Product ID"].astype(str).values:
                return render_template('update_product.html', error="Product not found", products=df.to_dict('records'))
            product = df[df["Product ID"].astype(str) == pid].iloc[0].to_dict()
            return render_template('update_product_details.html', product=product)
        elif 'update_submit' in request.form:
            pid = request.form['update_product_id']
            idx = df.index[df["Product ID"].astype(str) == pid].tolist()[0]
            if 'product_name' in request.form:
                df.at[idx, "Product Name"] = request.form['product_name'].strip()
            if 'category' in request.form:
                df.at[idx, "Category"] = request.form['category'].strip()
            if 'price' in request.form:
                try:
                    df.at[idx, "Price"] = float(request.form['price'])
                except ValueError:
                    product = df[df["Product ID"].astype(str) == pid].iloc[0].to_dict()
                    return render_template('update_product_details.html', product=product, error="Invalid price")
            if 'stock' in request.form:
                try:
                    df.at[idx, "Stock"] = int(request.form['stock'])
                except ValueError:
                    product = df[df["Product ID"].astype(str) == pid].iloc[0].to_dict()
                    return render_template('update_product_details.html', product=product, error="Invalid stock")
            save_inventory(df)
            return redirect(url_for('view_inventory'))
    return render_template('update_product.html', products=df.to_dict('records'))

@app.route('/record_sale', methods=['GET', 'POST'])
def record_sale():
    df = load_inventory()
    if request.method == 'POST':
        pid = request.form['product_id'].strip()
        if pid not in df["Product ID"].astype(str).values:
            return render_template('record_sale.html', error="Product not found", products=df.to_dict('records'))
        try:
            qty = int(request.form['quantity'])
        except ValueError:
            return render_template('record_sale.html', error="Invalid quantity", products=df.to_dict('records'))
        idx = df.index[df["Product ID"].astype(str) == pid].tolist()[0]
        current_stock = df.at[idx, "Stock"]
        if qty <= 0:
            return render_template('record_sale.html', error="Quantity must be positive", products=df.to_dict('records'))
        if current_stock < qty:
            return render_template('record_sale.html', error=f"Insufficient stock ({current_stock})", products=df.to_dict('records'))
        df.at[idx, "Stock"] = current_stock - qty
        df.at[idx, "Total Sales"] += qty
        save_inventory(df)
        return redirect(url_for('view_inventory'))
    return render_template('record_sale.html', products=df.to_dict('records'))

@app.route('/recommend_restock')
def recommend_restock():
    df = load_inventory()
    threshold = 10
    restock_items = df[df["Stock"] < threshold].to_dict('records')
    return render_template('recommend_restock.html', restock_items=restock_items, threshold=threshold)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
