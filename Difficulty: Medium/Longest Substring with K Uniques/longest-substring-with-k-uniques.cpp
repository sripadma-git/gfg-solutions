class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int count[26] = {0};
        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxi = INT_MIN;
        while(j < s.length()){
            count[s[j]-'a']++;
            if(count[s[j]-'a'] == 1){
               cnt++; 
            }
            if(cnt > k){
                int a = (j-1)-i+1;
                maxi = max(maxi,a);
                count[s[i]-'a']--;
                while(count[s[i]-'a'] != 0){
                    i++;
                    count[s[i]-'a']--;
                }
                i++;
                cnt = k;
            }
            j++;
        }
        if(cnt < k){
            return -1;
        }
        int a = (j-1)-i+1;
        maxi = max(maxi,a);
        return maxi;
    }
};