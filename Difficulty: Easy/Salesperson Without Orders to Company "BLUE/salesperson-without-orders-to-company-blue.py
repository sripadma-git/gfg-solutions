def find_salesperson_without_blue_orders(df_salesperson, df_orders, df_company):
    # Step 1: Get all com_id values for company named "BLUE"
    blue_com_ids = df_company[df_company["name"] == "BLUE"]["com_id"]
    
    # Step 2: Get all sales_ids who had orders with BLUE company
    sales_with_blue_orders = df_orders[df_orders["com_id"].isin(blue_com_ids)]["sales_id"].unique()
    
    # Step 3: Filter out salespersons who are NOT in sales_with_blue_orders
    result = df_salesperson[~df_salesperson["sales_id"].isin(sales_with_blue_orders)][["name"]]
    
    return result
