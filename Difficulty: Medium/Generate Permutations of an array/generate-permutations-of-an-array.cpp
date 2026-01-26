class Solution {
  public:
    bool permute(vector<int>&arr){
        int n = arr.size();
        int i = n-2;
        for(;i>=0 ; i--){
            if(arr[i]< arr[i+1])break;
        }
        if(i<0)return false;
        int j = i+1;
        for(; j <n ; j++){
            if(arr[j]<arr[i])break;
        }
        j--;
        swap(arr[i] , arr[j]);
        i++;
        sort(arr.begin() + i ,arr.end());
        return true;
        
        
        
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        sort(arr.begin() , arr.end());
        do{
            ans.push_back(arr);
        }while(permute(arr));
        return ans;

    }
};