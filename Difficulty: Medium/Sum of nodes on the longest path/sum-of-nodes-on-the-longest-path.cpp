/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
   pair<int,int> solve(Node* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        if(left.first>right.first){
            return {1+left.first,root->data+left.second};
        }
        else if(left.first==right.first){
            return {1+left.first,root->data+max(left.second,right.second)};
        }
        return {1+right.first,root->data+right.second};
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return solve(root).second;
        
    }
};