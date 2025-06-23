class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
           sort(arr.begin(), arr.end());
        
        int zeros = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                break;
            }
            zeros++;                             
        }

        int carry = 0;
        string ans = "";
        for(int i=arr.size()-1;i>=0 && i>=zeros;i-=2){
            int n1 = 0, n2 = 0;
            n1 = arr[i];
            if(i-1 >= 0){
                n2 = arr[i-1];
            }
            
            int sum = n1 + n2 + carry;            
            ans+=(sum%10 + '0');
            carry = sum/10;
        }
        
        if(carry) {
            ans+=(carry + '0');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};