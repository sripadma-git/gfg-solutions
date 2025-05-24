class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
         int n=s.size();
        int sum=stoi(s);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j+i<=n;j++)
            {
                string s1=s.substr(j, i);
                sum+=stoi(s1);
            }
        }
        return sum;
    }
};