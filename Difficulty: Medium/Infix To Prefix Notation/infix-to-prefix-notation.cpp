class Solution {
  public:
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

    string infixToPrefix(string s) {
        // Step 1: Reverse and swap brackets
        reverse(s.begin(), s.end());
        for (char &c : s) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        // Step 2: Convert to postfix
        stack<char> st;
        string result;

        for (char c : s) {
            if (isalpha(c)) {
                result += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop '('
            } else { // operator
                while (!st.empty() && 
                       ((precedence(c) < precedence(st.top())) || 
                        (precedence(c) == precedence(st.top()) && c != '^'))) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Step 3: Reverse postfix to get prefix
        reverse(result.begin(), result.end());
        return result;
    }
};
