class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,0));
        // return helper(n,m,x,dp);
        dp[0][0]=1;
        
        
        for(int dice=1;dice<=n;dice++){
            for(int target=1;target<=x;target++){
                int cnt=0;
                for(int i=1;i<=m;i++){
                    if(target>=i){
                       cnt+=dp[dice-1][target-i]; 
                    } else break;
                }
                dp[dice][target]=cnt;
            }
        }
        
        return dp[n][x];
    }
};