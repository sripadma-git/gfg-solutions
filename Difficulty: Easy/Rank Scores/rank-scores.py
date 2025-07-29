import pandas as pd

def find_rank_scores(df):
  """
  Ranks scores in a DataFrame according to the specified rules.

  Args:
    df (pd.DataFrame): A DataFrame with 'id' and 'score' columns.

  Returns:
    pd.DataFrame: A DataFrame with 'score' and 'rank' columns,
                  sorted by score in descending order.
  """
  # Create a new 'rank' column using the rank() method on the 'score' column.
  # - method='min': Assigns the same rank to tied scores and creates a gap.
  # - ascending=False: Ranks the scores from highest to lowest.
  # - .astype(int): Converts the rank from a float to an integer.
  df['rank'] = df['score'].rank(method='min', ascending=False).astype(int)
  
  # Sort the entire DataFrame by the 'score' column in descending order.
  df_sorted = df.sort_values(by='score', ascending=False)
  
  # Select only the 'score' and 'rank' columns as required.
  result_df = df_sorted[['score', 'rank']]
  
  # Reset the index to be sequential (0, 1, 2, ...).
  # drop=True prevents the old index from being added as a new column.
  # This was the final step needed to match the expected output format.
  return result_df.reset_index(drop=True)