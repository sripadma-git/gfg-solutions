class Solution:
    def countSquare(self, mat, x):
        n = len(mat)
        m = len(mat[0])
        
        # Step 1: Create prefix sum matrix
        prefix = [[0]*(m+1) for _ in range(n+1)]
        
        for i in range(n):
            for j in range(m):
                prefix[i+1][j+1] = (
                    mat[i][j]
                    + prefix[i][j+1]
                    + prefix[i+1][j]
                    - prefix[i][j]
                )

        def get_sum(r1, c1, r2, c2):
            # inclusive sum from (r1, c1) to (r2, c2)
            return (prefix[r2+1][c2+1]
                    - prefix[r1][c2+1]
                    - prefix[r2+1][c1]
                    + prefix[r1][c1])

        # Step 2: Check all square sizes and positions
        count = 0
        max_side = min(n, m)
        for size in range(1, max_side + 1):
            for i in range(n - size + 1):
                for j in range(m - size + 1):
                    if get_sum(i, j, i + size - 1, j + size - 1) == x:
                        count += 1
        return count
