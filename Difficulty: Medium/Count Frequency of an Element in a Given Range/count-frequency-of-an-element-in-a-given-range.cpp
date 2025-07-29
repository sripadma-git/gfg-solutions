#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> indexMap;
        
        // Preprocess: store all indices of each element
        for (int i = 0; i < arr.size(); i++) {
            indexMap[arr[i]].push_back(i);
        }

        vector<int> result;

        for (auto& q : queries) {
            int l = q[0], r = q[1], x = q[2];

            if (indexMap.find(x) == indexMap.end()) {
                result.push_back(0);
                continue;
            }

            auto& indices = indexMap[x];

            // Find number of indices in [l, r] using lower_bound and upper_bound
            int left = lower_bound(indices.begin(), indices.end(), l) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), r) - indices.begin();

            result.push_back(right - left);
        }

        return result;
    }
};
