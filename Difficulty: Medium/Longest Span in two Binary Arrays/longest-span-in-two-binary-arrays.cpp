class Solution {
  public:
     int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here.
         vector<int>temp(arr1.size());
        
        for(int i=0;i<arr1.size();i++){
            temp[i]=arr1[i]-arr2[i];
        }
        int ans =0 ;
        int rem =0 ;
        map<int,int>mp;
        for(int i=0;i<temp.size();i++){
            rem+=temp[i];
            if(rem == 0){
                ans = max(i+1,ans);
            }
            if(mp.find(rem)!=mp.end()){
                ans = max(ans,i-mp[rem]);
            }
            if(mp.find(rem)==mp.end()){
                mp[rem] = i;
            }
        }
        return ans;
    }
};