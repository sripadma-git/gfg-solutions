class Solution {
  public:
    bool isSumString(string &s) {
        // code here
         int n = s.size();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string a = s.substr(0, i);
                string b = s.substr(i, j - i);
                string remaining = s.substr(j);
                if (isValid(a, b, remaining)) return true;

    }
        }
        return false;
    }

    bool isValid(string a, string b, string remaining) {
        if (remaining.empty()) return true;
        string sum = addStrings(a, b);
        if (remaining.find(sum) == 0) {
            return isValid(b, sum, remaining.substr(sum.size()));
        }
        return false;
    }

    string addStrings(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string result;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }
        return result;
    }

    bool hasLeadingZeroes(string s) {
        return s.size() > 1 && s[0] == '0';
    }
};