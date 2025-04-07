#expt 2
import pandas as pd
import os

if not os.path.exists('stock.csv'):
    stock_df = pd.DataFrame(columns=['ProductID', 'ProductName', 'AvailableStock'])
    stock_df.to_csv('stock.csv', index=False)
    
if not os.path.exists('sales.csv'):
    sales_df = pd.DataFrame(columns=['ProductID', 'QuantitySold'])
    sales_df.to_csv('sales.csv', index=False)

stock_df = pd.read_csv('stock.csv')
sales_df = pd.read_csv('sales.csv')
merged_df = pd.merge(stock_df, sales_df, on='ProductID', how='left')
merged_df['QuantitySold'].fillna(0, inplace=True)
merged_df['RemainingStock'] = merged_df['AvailableStock'] - merged_df['QuantitySold']
restock_threshold = 10
merged_df['RestockNeeded'] = merged_df['RemainingStock'] < restock_threshold
merged_df['Suggested Restock Quantity'] = merged_df['RemainingStock'].apply(
    lambda x : 50 - x if x < restock_threshold else 0
)
restock_df = merged_df[merged_df['RestockNeeded']]
restock_df.to_csv('restock_recommendation.csv', index=False)