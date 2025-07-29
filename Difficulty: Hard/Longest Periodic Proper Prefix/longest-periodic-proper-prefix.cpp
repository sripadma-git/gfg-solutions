class Solution {
  public:
    int getLongestPrefix(string &s) {
        int n = s.size();

        for (int len = n - 1; len >= 1; --len) {
            string prefix = s.substr(0, len);
            string repeated = "";

            while (repeated.size() < n)
                repeated += prefix;

            if (repeated.substr(0, n) == s)
                return len;
        }

        return -1;
    }
};
