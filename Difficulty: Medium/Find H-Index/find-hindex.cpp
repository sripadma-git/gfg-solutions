class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
         int n=citations.size();
        int ans=0;
        sort(citations.begin(), citations.end()); // O(NlogN)
        for(int i=0;i<n;i++){
            if(citations[i]>=n-i) return n-i;
        }
        return 0;
    }
};