class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i-1] >  arr[i])return i;
        }
        return 0;
    }
};
