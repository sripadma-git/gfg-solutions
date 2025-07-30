class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
     map<char,pair<int,int>>omap;
        vector<int>pref;

        for(int i=0;i<s.length();i++) {
            
if (omap.find(s[i]) == omap.end()) {
                omap[s[i]] = {i, i};
            } else {
                omap[s[i]].second = i;
            }

            if(i==0) {
                pref.push_back((int)s.at(i));
            } else {
                pref.push_back((pref[(int)pref.size()-1]+(int)s.at(i)));
            }
        }
     
        vector<int>ans;
        for(auto i :omap) {
             int left = i.second.first;
                int right = i.second.second;
            if (left != right && left!=right-1) {
                if(right-1>=0) {
                    ans.push_back(pref[right-1]-pref[left]);
                }
            }
        }
        return ans;
            
    }
};