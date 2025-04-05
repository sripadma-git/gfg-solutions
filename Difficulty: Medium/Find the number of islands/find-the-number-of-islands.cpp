//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     // Arrays to explore all 8 directions (top-left, top, top-right, left, right, bottom-left, bottom, bottom-right)
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Depth-First Search to mark all connected 'L' cells as visited
    void dfs(int r, int c, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        // Traverse in all 8 directions
        for (int k = 0; k < 8; k++) {
            int nrow = r + row[k];
            int ncol = c + col[k];

            // Check for valid bounds and whether the cell is land ('L') and not yet visited
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 'L') {
                vis[nrow][ncol] = 1;  // Mark cell as visited
                dfs(nrow, ncol, m, n, vis, grid);  // Recursively explore connected land
            }
        }
    }

    // Function to count the number of islands (connected groups of 'L')
    int countIslands(vector<vector<char>>& grid) {
        int ans = 0;  // Final answer (number of islands)
        int m = grid.size();     // Number of rows
        int n = grid[0].size();  // Number of columns

        vector<vector<int>> vis(m, vector<int>(n, 0));  // Visited matrix

        // Traverse every cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell is unvisited and is land ('L'), it's a new island
                if (vis[i][j] == 0 && grid[i][j] == 'L') {
                    ans++;  // Increment island count
                    vis[i][j] = 1;  // Mark the cell as visited
                    dfs(i, j, m, n, vis, grid);  // Perform DFS to mark the whole island
                }
            }
        }

        return ans;  // Return the total number of islands
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends