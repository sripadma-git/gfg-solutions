class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
          int count =0;
        
        for ( int i =0 ; i< arr.size()-1 ; i++){
            
            count ++;
            
            if( arr[i]  > arr[i+1]){
                return count ;
            }
            
        }
        
//  here traversed the whole length means count == length and no rotation occured 
        return 0;
    }
};
