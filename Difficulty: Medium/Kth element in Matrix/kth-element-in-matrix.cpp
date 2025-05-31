class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size(), maxi = 0;
        
        int s = 1, e = 1e4, ans = -1;
        
        while(s <= e) {
            int mid = (s + e) / 2;
            
            int c1 = 0;
            for(int i = 0; i < n; i++) {
                
                int l = 0, r = n - 1, res = -1;
                
                while(l <= r) {
                    int m = (l + r) / 2;
                    
                    
                    if(matrix[i][m] < mid) {
                        res = m;
                        l = m + 1;
                    } else {
                        
                        r = m - 1;
                    }
                }
                
                
                c1 += (res + 1);
                
            }
            
            int c2 = 0;
            for(int i = 0; i < n; i++) {
                
                int l = 0, r = n - 1, res = -1;
                
                while(l <= r) {
                    int m = (l + r) / 2;
                    
                    
                    if(matrix[i][m] <= mid) {
                        res = m;
                        l = m + 1;
                    } else {
                        
                        r = m - 1;
                    }
                }
                
                
                c2 += (res + 1);
                
            }
            
            //cout << mid << " " << c1 << " " << c2 << endl;
            
            if(c1 <= k && k <= c2) {
                ans = mid;
                e = mid - 1;
            } else if(c2 < k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            
        }
        
        return ans;
        
    }
};