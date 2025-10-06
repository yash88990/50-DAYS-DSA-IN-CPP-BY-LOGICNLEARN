class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        int start = 0 , end = arr.size() - 1 , index = 0;
        while(index <= end){
            if(arr[index] < a ){
                swap(arr[index] , arr[start]);
                index++;
                start++;
            }else if(arr[index] > b ){
                swap(arr[index] , arr[end]);
                end--;
            }else{
                index++;
            }
        }
    }
};