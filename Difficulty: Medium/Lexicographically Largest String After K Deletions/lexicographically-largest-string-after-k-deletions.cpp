class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<int>st;
        for(int i=0;i<s.length();i++){
            while(!st.empty() && k && s[i]>s[st.top()])
            {
                st.pop();
                k--;
            }
            st.push(i);
        }
        string temp="";
        while(!st.empty()){
            temp+=s[st.top()];
            st.pop();
        }
        reverse(temp.begin(),temp.end());
       
        while(k){
            temp.pop_back();
            k--;
        }
        return temp;
    }
};
