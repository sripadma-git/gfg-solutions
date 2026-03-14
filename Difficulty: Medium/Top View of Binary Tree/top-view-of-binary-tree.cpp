/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
         map<int,int> mp;
        queue<pair<Node*,int>> pq;
        pq.push({root,0});
        
        int min_level = 0;
        int max_level = 0;
        
        while(!pq.empty()){
            
            Node* Current = pq.front().first;
            int axes = pq.front().second;
            pq.pop();
            
            min_level = min(min_level,axes);
            max_level = max(max_level,axes);
            
            if(Current->left!=NULL){
                pq.push({Current->left,axes-1});
            }
            
            if(Current->right!=NULL){
                pq.push({Current->right,axes+1});   
            }
            
            if(mp.find(axes)==mp.end()){
                mp[axes]=Current->data;
            }
        }
        
        vector<int> ans;
        for(int i=min_level;i<=max_level;i++){
            ans.push_back(mp[i]);
        }
        
        return ans;
    }
};