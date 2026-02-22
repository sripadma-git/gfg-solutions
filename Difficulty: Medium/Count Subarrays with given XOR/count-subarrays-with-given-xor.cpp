class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>store;
        store[0]=1;
        int xr=0;
        long long count=0;
        for(int x:arr){
            xr^=x;
            int need=xr^k;
            count+=store[need];
            store[xr]++;
        }
        return count;
    }
};