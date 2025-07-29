class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        unordered_set<int> skipSet(arr.begin(), arr.end());
        int count = 0, num = 1;

        while (true) {
            if (skipSet.find(num) == skipSet.end()) {
                count++;
                if (count == k) return num;
            }
            num++;
        }

        // Unreachable
        return -1;
    }
};
