/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool solve(Node* root,int min,int max){
        if(!root->left && !root->right){
            if(max == root->data+1 && min == root->data-1){
                return true;
            }
            return false;
        }
        if(root->left && solve(root->left,min,root->data)){
            return true;
        }
        if(root->right && solve(root->right,root->data,max)){
            return true;
        }
        return false;
    }
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root,0,INT_MAX);
        
    }
};