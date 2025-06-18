class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            if (i + 2 >= n) {
                return {}; 
            }
            vector<int> currentSubarray = { nums[i], nums[i + 1], nums[i + 2] };
            if (currentSubarray[2] - currentSubarray[0] > k) {
                return {}; 
            }
            result.push_back(currentSubarray);
        }
        return result;
    }
};