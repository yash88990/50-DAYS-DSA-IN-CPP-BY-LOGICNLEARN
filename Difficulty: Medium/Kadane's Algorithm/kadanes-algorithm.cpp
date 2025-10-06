class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int currentsum = 0;
        int maximumsum = INT_MIN;
        for(int i = 0 ; i < arr.size() ; i++){
            currentsum = max(arr[i] , currentsum + arr[i]);
            maximumsum = max(currentsum , maximumsum);
        }
        return maximumsum;
        
    }
};