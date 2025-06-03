class Solution {
  public:
      int countAtMostKdistinct(string &s, int k){
        int ans = 0;
        vector<int> hash(26, 0);
        int count = 0;
        
        int l=0, r=0;
        int n = s.size();
        
        while(r < n){
            if(hash[s[r]-'a'] == 0)
                count++;
            
            hash[s[r]-'a']++;
            while(count > k){
                hash[s[l]-'a']--;
                if(hash[s[l]-'a'] == 0)
                    count--;
                l++;    
            }
            
            ans += (r-l+1);
            r++;
        }
        return ans;
    }
  
    int countSubstr(string& s, int k) {
        // code here.
        return countAtMostKdistinct(s, k) - countAtMostKdistinct(s, k-1);
    }
};