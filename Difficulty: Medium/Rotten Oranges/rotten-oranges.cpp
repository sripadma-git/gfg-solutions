//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
         int fresh=0;
        queue<pair<int,int>> q;
        int n=mat.size();
        int m=mat[0].size();
        int res=0;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        
        //finding  total fresh oranges and position of rotten oranges
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           if(mat[i][j]==1) fresh++;
           else if(mat[i][j]==2) q.push({i,j});
           
           
       //if their is no fresh orange or rotten orange then 
       //we already knew the answer
       while(fresh>0 && !q.empty()){
            int size=q.size();
            //Calculating time 
            res++;
            for(int i=0;i<size;i++){
                //fetching position of rotten oranges
                  int rw=q.front().first;
                  int cw=q.front().second;
                  q.pop();
                  //this loop is for up , down , left , right position check
                  for(int k=0;k<4;k++){
                      int fr=rw+row[k];
                      int fc=cw+col[k];
                      //we are only interested for a valid indexes as well
                      //it is a fresh oranges
                      if(fr>=0 && fr<n && fc>=0 && fc<m && mat[fr][fc]==1){
                          mat[fr][fc]=2;
                          q.push({fr,fc});
                          //as this orange is rotten so reduces fresh orange 
                          //by one
                          fresh--;
                      }
                  }
                
            }
       }
       //if their is no fresh oranges means all oranges rotten 
       if(fresh==0) return res;
       //if their is still fresh oranges left it means it's impossible to rotten all
       //the oranges
       return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends