class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int s = 1, e = *max_element(arr.begin(), arr.end());
        int ans = INT_MAX;
        while(s <= e){
            int mid = s + (e - s) / 2;
            int divisor = 0;
            for(int ele : arr) divisor += (ele + mid - 1) / mid; // Gives Ceiling Value
            if(divisor <= k){
                ans = min(ans, mid);
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};
