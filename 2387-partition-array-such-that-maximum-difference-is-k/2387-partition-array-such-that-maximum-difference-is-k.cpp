
class Solution {
public:
    // Function to determine the minimum number of groups with each group having differences
    // between numbers not greater than k.
    int partitionArray(vector<int>& nums, int k) {
        // Sort the input vector to make it easier to group elements.
        sort(nums.begin(), nums.end());

        // Initialize 'groupsCount' to 1 since the first element starts the first group.
        int groupsCount = 1;
        // The 'currentGroupStart' is the first element in the current group.
        int currentGroupStart = nums[0];

        // Iterate through the sorted numbers.
        for (int& currentNum : nums) {
            // If the difference between the current number and the start of the current group
            // is greater than k, a new group must be started.
            if (currentNum - currentGroupStart > k) {
                // Update 'currentGroupStart' to the current number.
                currentGroupStart = currentNum;
                // Increment the 'groupsCount' as a new group is created.
                groupsCount++;
            }
        }
        // Return the total number of groups created.
        return groupsCount;
    }
};
