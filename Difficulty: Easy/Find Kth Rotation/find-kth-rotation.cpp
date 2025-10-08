class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        // for(int i = 0 ; i < arr.size() -1 ; i++){
        //     if(arr[i] > arr[i+1])return i + 1 ;
        // }
        // return 0;
        
        int s = 0 , e = arr.size() - 1;
        while(s < e ){
            int m = s + ( e - s )/2;
            if(arr[m] < arr[e])e = m;
            else s = m + 1 ;
            
        }
        return e;
        
        
    }
};
