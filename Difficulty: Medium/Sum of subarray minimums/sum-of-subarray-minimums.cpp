class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
          int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) right[i] = n;
            else right[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            ans += (long long)arr[i] * leftCount * rightCount;
        }

        return ans;
    }
};