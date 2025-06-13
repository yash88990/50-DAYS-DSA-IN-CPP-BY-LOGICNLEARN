
class Solution {
public:
    // Function to minimize the maximum difference between pairs after 'p' pairs have been removed
    int minimizeMax(std::vector<int>& nums, int pairsToRemove) {
        // First, sort the array to easily identify and remove pairs with minimal differences
        std::sort(nums.begin(), nums.end());
      
        // Store the number of elements in 'nums'
        int numCount = nums.size();
      
        // Initialize the binary search bounds for the minimal max difference
        int leftBound = 0, rightBound = nums[numCount - 1] - nums[0] + 1;
      
        // Lambda function to check if 'diff' is sufficient to remove 'pairsToRemove' pairs
        auto check = [&](int diff) -> bool {
            int pairsCount = 0; // Keep track of the number of pairs removed
          
            // Iterate over the sorted numbers and attempt to remove pairs
            for (int i = 0; i < numCount - 1; ++i) {
                // If the difference between a pair is less than or equal to 'diff'
                if (nums[i + 1] - nums[i] <= diff) {
                    pairsCount++; // Increment the count of removed pairs
                    i++; // Skip the next element as it's part of a removed pair
                }
            }
          
            // True if enough pairs can be removed, false otherwise
            return pairsCount >= pairsToRemove;
        };
      
        // Perform binary search to find the minimal max difference
        while (leftBound < rightBound) {
            int mid = (leftBound + rightBound) >> 1; // Equivalent to average of the bounds
            if (check(mid)) {
                // If 'mid' allows removing enough pairs, look for a potentially lower difference
                rightBound = mid;
            } else {
                // Otherwise, increase 'mid' to allow for more pairs to be removed
                leftBound = mid + 1;
            }
        }
      
        // The left bound will be the minimal max difference after the binary search
        return leftBound;
    }
};
