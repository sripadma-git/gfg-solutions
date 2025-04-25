//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
           sort(arr.begin(), arr.end());
        if(arr.size()%2 != 0)
        {
            for(int i = 0; i <= (arr.size())/2; i++)
            {
                if(arr[i] == arr[i + arr.size()/2])
                    return arr[i];
            }
        }
        else
        {
            for(int i = 0; i < (arr.size())/2; i++)
            {
                if(arr[i] == arr[i + arr.size()/2])
                    return arr[i];
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends