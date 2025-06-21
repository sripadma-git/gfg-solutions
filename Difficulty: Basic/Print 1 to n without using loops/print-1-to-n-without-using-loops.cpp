// User function Template for C++
class Solution {
  public:
    void printTillN(int n) {
        // Write Your Code here
           if(n==0)  //base case
        {
            return;
        }else    
        {
            printTillN(n-1);   // recursive case
            cout<<n<<" ";
        }
    }
};