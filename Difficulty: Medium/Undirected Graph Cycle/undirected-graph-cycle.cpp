//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool dfs(unordered_map<int,vector<int>>& adj, int u, int parent, vector<bool>& visited) {
        
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(v == parent){
                continue;
            }
            if(visited[v]){
                return true;
            }
            if(!visited[v] && dfs(adj,v,u,visited)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> adj;
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V,false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && dfs(adj,i,-1,visited)){
                return true;
            }
        }
        return false;
        // Code here
        
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends