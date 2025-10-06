class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int start = 0 , end = arr.size() -1  , index = 0;
        while(index <= end){
            if(arr[index] == 0){
                //swap with start
                swap(arr[start] , arr[index]);
                start++;
                index++;
            }else if(arr[index] == 2){
                swap(arr[end] , arr[index]);
                end--;
            }else{
                index++;
                
            }
            
        }
    }
};