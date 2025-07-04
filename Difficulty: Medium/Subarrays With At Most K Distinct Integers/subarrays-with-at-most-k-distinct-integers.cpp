class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
          int ans=0;
        int s=0,e=0;
        map<int,int>mp;
        while(e<arr.size())
        {
            mp[arr[e]]++;
            while(mp.size()>k)
            {
                mp[arr[s]]--;
                if(!mp[arr[s]])mp.erase(arr[s]);
                s++;
            }
            if(mp.size()<=k)ans+=e-s+1;
            e++;
        }
        return ans;
    }
};