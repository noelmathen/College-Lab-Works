import pandas as pd
import os

def add_product(filename):
    print("\n-----Add New Product-----")
    df = pd.read_csv(filename)
    id = input('Enter Product ID: ').strip()
    if id in df['Id'].astype(str).values:
        print(f"Product with is [{id}] already exists...")
        return
    
    name = input('Enter product name: ').strip()
    category = input('Enter product category: ').strip()
    
    try:
        stock = int(input("Enter current stock: "))
        price = int(input("Enter current price: "))
    except ValueError:
        print("Invalid input, try again")
        return
    
    sales = 0
    
    df.loc[len(df)] = [id, name, category, price, stock, sales]
    df.to_csv(filename, index=False)

def update_product(filename):
    df = pd.read_csv(filename)
    print("\nUpdate a product")
    
    id = input("Enter Product ID to edit: ").strip()
    if not id in df["Id"].astype(str).values:
        print("Item does not exist!")
        return
    
    row = df[df["Id"].astype(str) == id].index[0]
    # print(row)
    fields = {
        "1" : "Name",
        "2" : "Category",
        "3" : "Price",
        "4" : "Stock"
    }
    for k, v in fields.items():
        print(f"{k}. {v}")
    choice = input("Enter a choice: ")
    
    new_item = input(f"Enter new {fields[choice]}: ").strip()
    
    if choice == "3" or choice == "4":
        try:
            new_item = int(new_item) if choice == 4 else float(new_item)
        except:
            print("Invalid Input. Tryagain")
            return
    
    df.at[row, fields[choice]] = new_item
    df.to_csv(filename, index=False)
    


def search_inventory(filename):
    df = pd.read_csv(filename)
    print("Search for a product")
    query = input("Enter Product ID or Product Name: ").strip().lower()

    results = df[
        df["Id"].astype(str).str.lower().str.contains(query) | 
        df["Name"].astype(str).str.lower().str.contains(query)
    ]
    
    if results.empty:
        print("Item not found")
        return
    print(results.to_string(index=False))

def view_inventory(filename):
    df = pd.read_csv(filename)
    if df.empty:
        print("Inventoryu empty")
        return
    print(df.to_string(index=False))


def record_sale(filename):
    df = pd.read_csv(filename)
    
    id = input("Enter Product ID: ").strip()
    if id not in df["Id"].astype(str).values:
        print(f"Error: Product ID {id} not found.")
        return

    try:
        quantity_sold = int(input("Enter the quantity sold: "))
    except ValueError:
        print("Invalid quantity. Aborting sale record.")
        return
    
    row = df[df["Id"].astype(str) == id].index[0]
    current_stock = df.at[row, "Stock"]
    
    if current_stock < quantity_sold:
        print(f"Error: Insufficient stock ({current_stock}) for product {id}.")
        return
    if quantity_sold < 0:
        print("Error: Quantity sold must be positive.")
        return
    
    df.at[row, "Stock"] -= quantity_sold
    df.at[row, "Sales"] += quantity_sold
    
    df.to_csv(filename, index=False)  

def recommend_restock(filename, threshold):
    df = pd.read_csv(filename)
    restock_df = df[df["Stock"] < threshold]
    if restock_df.empty:
        print("No need of restocking!")
        return
    print("Restock the following items:")
    print(restock_df.to_string(index=False))


#CODE STARTING HERE
filename = 'inventory.csv'

if not os.path.exists(filename):
    stock_csv = pd.DataFrame(columns=['Id', 'Name', 'Category', 'Price', 'Stock', 'Sales'])
    stock_csv.to_csv('inventory.csv', index=False)

while True:
    print("\n---MAIN MENU---")
    print("1. Add Product")
    print("2. Update Product")
    print("3. Search Inventory")
    print("4. View Inventory")
    print("5. Record Sale")
    print("6. Recommend Restock")
    print("7. Exit")
    choice = input('Enter your choice: ').strip()
    if choice == "1":
        add_product(filename)
    elif choice == "2":
        update_product(filename)
    elif choice == "3":
        search_inventory(filename)
    elif choice == "4":
        view_inventory(filename)
    elif choice == "5":
        record_sale(filename)
    elif choice == "6":
        recommend_restock(filename, 10)
    elif choice == "7":
        print("\nExiting...Thankyou!\n")
        break
    else:
        print('Invalid Input, Try Again')
        continue
