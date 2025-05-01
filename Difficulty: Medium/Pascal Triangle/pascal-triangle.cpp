//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
          if(n==1)    return {1};
        vector<int> helper;
        vector<int> res={1};
        
        for(int i=0 ; i<n-1 ; i++)
        {
            helper.push_back(res[0]);
            for(int j=0 ; j<res.size()-1 ; j++)
            {
                helper.push_back(res[j]+res[j+1]);
            }
            helper.push_back(res[res.size()-1]);
            res=helper;
            helper={};
        }
        return res;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends