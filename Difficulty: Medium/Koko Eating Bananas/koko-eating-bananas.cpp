class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        sort(arr.begin(),arr.end());
        int s = 1;
        int e = arr[arr.size()-1];
        int mid = s+(e-s)/2;
        int mini = INT_MAX;
        while(s<=e){
            int cnt = 0;
            int a = mid;
            for(int i = 0;i<arr.size();i++){
                if(arr[i] <= a){
                    cnt++;
                }
                else{
                    int c = arr[i];
                    while(c > a){
                        cnt++;
                        c = c-a;
                    }
                    cnt++;
                }
            }
            if(cnt<=k){
                mini = min(mini,a);
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s+(e-s)/2;
        }
        return mini;
    }
};