//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
           unordered_map<char, int> real;
        int n = str.size();
        for(auto ele : str)
            real[ele]++;
        
        int realSize = real.size();
        
        int i=0, j=0;
        unordered_map<char, int> temp;
        int ans = INT_MAX;
        
        while(j<n){
            temp[str[j]]++;
            while(temp.size() == realSize){
                ans = min(ans, j-i+1);
                if(temp[str[i]]==1)
                    temp.erase(str[i]);
                else
                    temp[str[i]]--;
                
                i++;
                if(i>=n)
                    break;
            }
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends