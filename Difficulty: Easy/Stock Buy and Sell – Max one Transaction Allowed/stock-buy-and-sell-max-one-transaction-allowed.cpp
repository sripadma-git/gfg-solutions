class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
         int mn=1e9,profit=0;
        for(auto it:prices)
        {
            profit=max(profit,it-mn);
            mn=min(mn,it);
        }
        return profit>0?profit:0;
        
    }
};
