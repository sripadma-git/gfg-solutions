class Solution {
  public:
  
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int l = *min_element(heights.begin(), heights.end());
        int r = *max_element(heights.begin(), heights.end());
        int min_cost = INT_MAX;
        bool flag = true;
        
        function<int(int)> helper = [&](int mid)->int
        {
            int c = 0;
            for(int i = 0;i<heights.size();i++)
            {
                c = c + abs(mid - heights[i]) * cost[i];
            }
            return c;
        };
        while(l<=r && flag)
        {
            int mid = (l+r)/2;
            int c = helper(mid);
            int p = helper(mid-1);
            int n = helper(mid+1);
            if(c<=p && c<=n)
            {
                min_cost = c;
                flag = false;
                break;
            }
            else if(c>p && c<=n)
            {
                r = mid -1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return min_cost;
    }
};