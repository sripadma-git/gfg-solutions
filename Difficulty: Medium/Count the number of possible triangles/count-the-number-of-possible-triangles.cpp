class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
             int res=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int left=0;
            int right=i-1;
            while(left<right){
                if(arr[left]+arr[right]>arr[i]){
                    res+=right-left;
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return res;
    }
};
