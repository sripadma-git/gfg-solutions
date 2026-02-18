class Solution {
  public:

    long long mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        
        int i = left;      // left subarray pointer
        int j = mid + 1;   // right subarray pointer
        int k = 0;
        long long invCount = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                
                // All remaining elements in left subarray form inversions
                invCount += (mid - i + 1);
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        // Copy back to original array
        for (int p = 0; p < temp.size(); p++) {
            arr[left + p] = temp[p];
        }

        return invCount;
    }

    long long mergeSortAndCount(vector<int> &arr, int left, int right) {
        long long invCount = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            invCount += mergeSortAndCount(arr, left, mid);
            invCount += mergeSortAndCount(arr, mid + 1, right);
            invCount += mergeAndCount(arr, left, mid, right);
        }

        return invCount;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
