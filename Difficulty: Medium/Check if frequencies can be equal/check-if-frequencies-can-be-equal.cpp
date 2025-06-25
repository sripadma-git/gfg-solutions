class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        unordered_map<char, int> mp;
        for (auto i : s)  mp[i]++;
       unordered_map<int, int> v;
        for (auto i : mp)  v[i.second]++;
        if (v.size() == 1) return true;
        for (auto it : mp) 
        {
            mp[it.first]--; 
            unordered_map<int, int> v;
            for (auto i : mp) 
            {
                if (i.second > 0) v[i.second]++;
            }
            if (v.size() == 1) return true; 
            mp[it.first]++;  
        }
        return false;
    }
};