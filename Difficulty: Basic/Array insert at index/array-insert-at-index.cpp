class Solution {
  public:
    void insertAtIndex(vector<int> &arr, int index, int val) {
        // code here
        //method 1 
        // arr.insert(arr.begin() + index, val);
        
        //method 2 
        int n = arr.size();
        arr.resize(n+1);
        for(int i = n; i > index ; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = val;
    }
};
