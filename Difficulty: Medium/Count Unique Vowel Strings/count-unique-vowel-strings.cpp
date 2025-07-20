class Solution {
  public:
    int vowelCount(string& s) {
        // code here
           int arr[5]={0};
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a') arr[0]++;
            else if(s[i]=='e') arr[1]++;
            else if(s[i]=='i') arr[2]++;
            else if(s[i]=='o') arr[3]++;
            else if(s[i]=='u') arr[4]++;
        }
        
        int count=0;
        for(int i=0;i<5;i++) if(arr[i]!=0) count++;
        
        if(count==0) return 0;
        int ans=1;
        while(count)
        {
            ans= ans*count;
            count--;
        }
        
        for(int i=0;i<5;i++)
        {
           if(arr[i]!=0) ans =ans*arr[i];
        }
        
        return ans;
    }
};