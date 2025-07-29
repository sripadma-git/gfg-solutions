def delete_duplicate_phone_numbers(df):
    # Sort by id to prioritize the smallest id
    df_sorted = df.sort_values(by='id')

    # Drop duplicates based on 'phone', keeping the one with the smallest id
    result = df_sorted.drop_duplicates(subset='phone', keep='first')

    # Do NOT reset index
    return result.sort_values(by='id')
