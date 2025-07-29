class Solution {
  public:
    int countPairs(vector<string>& arr) {
        // code here
         unordered_map<string, int> maskCount;
        int count = 0;

        for (const string& s : arr) {
            for (int i = 0; i < s.size(); ++i) {
                string masked = s;
                masked[i] = '*'; // Replace one character with '*'
                count += maskCount[masked]; // Add number of matches seen so far
                maskCount[masked]++;
            }
        }

        return count;
    }
};