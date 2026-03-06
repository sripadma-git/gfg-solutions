class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        if (p.length() > s.length()) return "";

        unordered_map<char, int> required;
        for (char ch : p) required[ch]++;

        int start = 0, minLen = INT_MAX, minStart = 0;
        int count = p.length(); // total characters to match

        for (int end = 0; end < s.length(); end++) {
            char ch = s[end];
            if (required[ch] > 0) count--;
            required[ch]--;

            // When all characters are matched
            while (count == 0) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                // Try to shrink the window
                required[s[start]]++;
                if (required[s[start]] > 0) count++;
                start++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};