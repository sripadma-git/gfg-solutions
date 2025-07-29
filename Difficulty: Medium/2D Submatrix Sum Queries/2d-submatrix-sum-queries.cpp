class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 0));
        vector<int> ans;

        // Step 1: Build the prefix sum matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pre[i][j] = mat[i][j];
                if (i > 0) pre[i][j] += pre[i-1][j];
                if (j > 0) pre[i][j] += pre[i][j-1];
                if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
            }
        }

        // Step 2: Answer each query using the prefix sum matrix
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            int sum = pre[r2][c2];
            if (r1 > 0) sum -= pre[r1 - 1][c2];
            if (c1 > 0) sum -= pre[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += pre[r1 - 1][c1 - 1];
            ans.push_back(sum);
        }

        return ans;
    }
};
