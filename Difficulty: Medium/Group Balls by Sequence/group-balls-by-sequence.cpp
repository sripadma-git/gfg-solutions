class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
         int n = arr.size();
        if(n % k != 0)  return false;
        
        unordered_map<int,int> mp;
        for(int num: arr)    mp[num]++;
        sort(arr.begin(), arr.end());   // necessary
        
        for(int num: arr){
            if( mp[num] == 0)   continue;   // skip and choose next one
            for(int i = 0; i < k; i++){
                if(mp[num + i] == 0)    return false;
                mp[num + i]--;
            }
        }
        return true;
    }
};