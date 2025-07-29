def find_department_id(df_employees, df_employee_dept):
    # Perform a left join to keep all employees and add department_id where available
    result = df_employees.merge(df_employee_dept, on="id", how="left")
    
    return result[["id", "name", "department_id"]]
