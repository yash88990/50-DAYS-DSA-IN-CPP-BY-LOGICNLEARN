// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

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
   void solve(vector<int>&arr , int n){
       for(int i = n / 2 - 1 ; i >= 0 ; i--){
        heapify(arr, n , i);
    }
   }

    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        solve(arr, n);
        for(int i = n-1 ; i >= 0 ;i--){
            swap(arr[i] , arr[0]);
            heapify(arr , i , 0);
        }
        
        
    }
};