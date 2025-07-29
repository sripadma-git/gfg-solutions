def average_salary_by_department(df):
    #Code Herdef average_salary_by_department(df):
    # Group by 'department' and calculate the mean salary
    result = df.groupby("department", as_index=False)["salary"].mean()
    
    # Rename the column to 'average_salary'
    result.rename(columns={"salary": "average_salary"}, inplace=True)
    
    # Sort the result by department in ascending order
    return result.sort_values("department").reset_index(drop=True)
