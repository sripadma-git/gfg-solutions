class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
         vector<int>f(26, 0);
        for(char &ch:s){
            f[ch-'a']++;
        }
        
        priority_queue<int>pq(f.begin(), f.end());
        
        for(int i=0; i<k; i++){
            int top=pq.top();
            pq.pop();
            pq.push(top-1);
        }
        
        int ans=0;
        
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            ans+=(top*top);
        }
        
        return ans;
    }
};