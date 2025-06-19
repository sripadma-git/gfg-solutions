class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string u="",l="";
        for(auto &c:s){
            if(c>='A' && c<='Z') u+=c;
            else l+=c;
        }
        
        int i=0,j=0;
        sort(u.begin(),u.end());
        sort(l.begin(),l.end());
        for(auto &c:s){
            if(c>='A' && c<='Z') c=u[i++];
            else c=l[j++];
        }
        return s;
    }
};