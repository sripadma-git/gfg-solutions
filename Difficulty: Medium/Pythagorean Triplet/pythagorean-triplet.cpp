class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
         int n =arr.size();
        unordered_map<int,int>freq;
        for(int i=0;i <n;i++){
            int sq=arr[i]*arr[i];
            freq[sq]++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j< n; j++){
                int a2=arr[i]*arr[i];
                int b2=arr[j]*arr[j];
                int sum=a2 +b2;
                if(freq.find(sum)!=freq.end()){
                    if(sum!=a2 && sum!=b2) 
                        return true;
                    else if(sum==a2 && freq[a2]>1) 
                        return true;
                    else if(sum==b2 && freq[b2]>1) 
                        return true;
                }
            }
        }
        return false;
    }
};