class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low < high){
            int index = partition(arr , low , high);
            quickSort(arr , low , index - 1 );
            quickSort(arr  , index + 1 , high);
        }
        
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivot = arr[low];
        int k = high;
        for(int i = high ; i > low ; i--){
            if(arr[i] >  pivot){
                swap(arr[i] , arr[k--]);
            }
        }
        swap(arr[low] , arr[k]);
        return k;
    }
};