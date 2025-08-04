class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int ans = INT_MIN;
        int n = mat.size();int m = mat[0].size();
        for(int t=0;t<n;t++){
            vector<int>temp(m,0);
            for(int b=t;b<n;b++){
                for(int k=0;k<m;k++){
                    temp[k] += mat[b][k];
                }
                //1d kadane on temp
                int maxi = INT_MIN;
                int curr = 0;
                for(int i=0;i<m;i++){
                    curr += temp[i];
                    maxi = max(maxi,curr);
                    if(curr < 0){
                        curr = 0;
                    }
                }
                ans = max(ans,maxi);
            }
        }
        return ans;
    }
};
