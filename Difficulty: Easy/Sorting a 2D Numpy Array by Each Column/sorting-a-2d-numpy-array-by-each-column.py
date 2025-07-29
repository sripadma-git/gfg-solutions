import numpy as np

def sort_by_column(arr):
    """
    Sort a 2D NumPy array by each column in ascending order.
    
    Parameters:
    arr: numpy.ndarray
        The input 2D NumPy array
    
    Returns:
    numpy.ndarray
        The array with each column sorted in ascending order
    """
    # Ensure the input is a NumPy array
    arr = np.array(arr)
    
    # Sort along axis 0 (columns)
    # np.sort sorts along the specified axis
    result = np.sort(arr, axis=0)
    
    return result