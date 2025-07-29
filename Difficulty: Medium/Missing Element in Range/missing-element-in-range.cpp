class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> elements(arr.begin(), arr.end());
        vector<int> missing;

        for (int num = low; num <= high; ++num) {
            if (elements.find(num) == elements.end()) {
                missing.push_back(num);
            }
        }

        return missing;
    }
};
