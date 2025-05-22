//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
          map<Node*, Node*>parents;
        queue<Node*>q1;
        q1.push(root);
        Node* targetnode = NULL;
        while(!q1.empty())
        {
            int s = q1.size();
            for(int i=0;i<s;i++)
            {
                
                Node* node = q1.front();
                q1.pop();
                
                // get here target node by using target value
                if(node->data == target)targetnode = node;
                
                if(node->left)
                {
                    parents[node->left] = node;
                    q1.push(node->left);
                }
                if(node->right)
                {
                    parents[node->right] = node;
                    q1.push(node->right);
                }
                
            }
            
        }
            
        map<Node*, bool>burned;
        queue<Node*>q2;
        q2.push(targetnode);
        burned[targetnode] = true;
        int required_sec = -1;
            
        while(!q2.empty())
        {
            int s = q2.size();
            required_sec++;
            for(int i=0;i<s;i++)
            {
                Node* current = q2.front();
                q2.pop();
                
                if(!burned[current->left]&&current->left)
                {
                    q2.push(current->left);
                    burned[current->left] = true;
                }
                
                if(!burned[current->right]&&current->right)
                {
                    q2.push(current->right);
                    burned[current->right] = true;
                }
                
                if(!burned[parents[current]]&&parents[current])
                {
                    q2.push(parents[current]);
                    burned[parents[current]] = true;
                }
            }
        }
                
        return required_sec;  
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends