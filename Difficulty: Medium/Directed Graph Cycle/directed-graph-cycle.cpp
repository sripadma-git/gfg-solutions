//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>in(V,0);
        vector<vector<int>>g(V);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
        }
        for(auto vec:g){
            for(auto val:vec){
                in[val]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        vector<int>vec;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vec.push_back(curr);
            for(auto adj:g[curr]){
                in[adj]--;
                if(in[adj] == 0){
                    q.push(adj);
                }
            }
        }
        return vec.size() < V;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends