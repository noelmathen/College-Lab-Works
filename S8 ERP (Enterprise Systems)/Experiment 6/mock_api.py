from flask import Flask, request, jsonify
import pandas as pd
import os

app = Flask(__name__)

# Path to the Excel file (Supplier System)
EXCEL_FILE = 'supplier_data.xlsx'

# Load Excel file if exists, else create a new one
def load_excel():
    if not os.path.exists(EXCEL_FILE):
        data = {
            'ProductName': ['Rice', 'Sugar', 'Wheat', 'Tea Powder', 'Salt'],
            'Stock': [500, 300, 50, 150, 300],
            'UnitPrice': [2, 1.2, 1.5, 8, 0.5],
            'SupplierName': ['XYZ Supplier', 'LMN Supplier', 'ABC Supplier', 'PQR Supplier', 'XYZ Supplier']
        }
        df = pd.DataFrame(data)
        df.to_excel(EXCEL_FILE, index=False)
    return pd.read_excel(EXCEL_FILE)

# Function to save the updated data to the Excel file
def save_excel(df):
    df.to_excel(EXCEL_FILE, index=False)

# Route to get all products from supplier
@app.route('/api/products', methods=['GET'])
def get_products():
    df = load_excel()
    return jsonify(df.to_dict(orient='records'))

# Route to place an order
@app.route('/api/order', methods=['POST'])
def place_order():
    order_data = request.get_json()
    product_name = order_data.get('ProductName')  # Changed from ProductID to ProductName
    quantity = order_data.get('Quantity')

    df = load_excel()

    # Debug: print the column names to verify they are correct
    print(df.columns)

    # Check if product exists by ProductName
    if product_name not in df['ProductName'].values:
        return jsonify({'error': 'Product not found'}), 404

    # Get the product row by ProductName
    product_index = df[df['ProductName'] == product_name].index[0]
    available_stock = df.at[product_index, 'Stock']

    # Check if stock is available
    if available_stock < quantity:
        return jsonify({'error': 'Not enough stock available'}), 400

    # Reduce the stock
    df.at[product_index, 'Stock'] -= quantity
    save_excel(df)

    # Convert int64 to native Python int before returning
    return jsonify({'message': 'Order placed successfully', 'remaining_stock': int(df.at[product_index, 'Stock'])})

if __name__ == '__main__':
    app.run(debug=True)
