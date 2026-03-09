class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        vector<pair<int,int>>vec(s.size());
        for(int i = s.size()-1;i>=0;i--){
            if(i == s.size()-1){
                vec[i] = {s[i] - '0', i};
                continue;
            }
            if(s[i]-'0' > vec[i+1].first){
                vec[i] = {s[i] - '0', i};
            }else{
                vec[i] = vec[i+1];
            }
        }
        for(int i = 0;i<s.size();i++){
            if(s[i] - '0' < vec[i].first){
                char temp1 = s[i];
                char temp2 = s[vec[i].second];
                s[i] = temp2;
                s[vec[i].second] = temp1;
                return s;
            }
        }
        return s;
    }
};