def find_invalid_comments(df):
    # Filter rows where content length is strictly greater than 20
    invalid_df = df[df['content'].str.len() > 20]
    
    # Return only the comment_id column
    return invalid_df[['comment_id']]
