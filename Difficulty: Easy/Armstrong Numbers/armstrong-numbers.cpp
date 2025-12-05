// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int temp=n;
        int value=0;
        while(n>0){
            int rem = n%10;
            int cube = rem*rem*rem;
            
            value = value + cube;
             n = n/10;
        }
        if ( temp == value){
            return true;
        }
        
            return false;
        
       
    }
};