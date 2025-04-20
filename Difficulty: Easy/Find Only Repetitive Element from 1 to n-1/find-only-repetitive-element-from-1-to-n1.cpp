//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
         for(int i = 0; i < arr.size(); i++) {
        int index = arr[i] - 1;
        
        if(arr[index] != arr[i]) {
            swap(arr[i], arr[index]);
            i--; // After swapping, we need to recheck the new element at index i,
                 // as it may also be out of place. Hence, we decrement i to stay
                 // on the same index in the next iteration.
        }
    }
    // At the end of the rearrangement, the duplicate will be at the last position
    return arr[arr.size() - 1];
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends