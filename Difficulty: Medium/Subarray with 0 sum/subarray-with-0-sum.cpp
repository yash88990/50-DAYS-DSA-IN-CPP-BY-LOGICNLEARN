class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n= arr.size();
        unordered_set<int> prefixSums;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            if (sum == 0 || prefixSums.find(sum) != prefixSums.end()) {
                return true;
            }
            prefixSums.insert(sum);
        }
        return false;
    }
};