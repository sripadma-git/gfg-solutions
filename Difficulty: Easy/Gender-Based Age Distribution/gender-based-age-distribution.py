def median_age_by_gender(df):
    # Group by 'gender' and calculate the median of 'age'
    result = df.groupby("gender", as_index=False)["age"].median()
    
    # Rename the column to 'median_age'
    result.rename(columns={"age": "median_age"}, inplace=True)
    
    # Sort by gender in ascending order
    return result.sort_values("gender").reset_index(drop=True)
