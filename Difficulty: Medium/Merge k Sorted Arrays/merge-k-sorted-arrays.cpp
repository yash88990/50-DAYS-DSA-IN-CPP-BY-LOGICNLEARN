class Solution {
  public:
   void heapify(vector<int>&arr , int n , int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[largest] < arr[left])largest = left;
    if(right < n && arr[largest] < arr[right])largest = right;
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr , n , largest);
    }
}

    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        vector<int>ans;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < arr[0].size() ; j++){
                ans.push_back(arr[i][j]);
            }
        }
        
         int size = ans.size();
         
         for(int i = size / 2 - 1 ; i >= 0 ; i--){
              heapify(ans , size , i);
         }
         
         for(int i = size-1 ; i >= 0 ;i--){
            swap(ans[i] , ans[0]);
            heapify(ans , i , 0);
        }
          return ans;
    }
};