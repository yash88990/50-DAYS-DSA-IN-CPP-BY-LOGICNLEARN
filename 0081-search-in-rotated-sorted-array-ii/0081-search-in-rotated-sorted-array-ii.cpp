class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;

            if (nums[m] == target) return true;

            // Handle duplicates
            if (nums[s] == nums[m] && nums[m] == nums[e]) {
                s++;
                e--;
                continue; // Important to skip further checks in this iteration
            }

            // Left part sorted
            if (nums[m] >= nums[s]) {
                if (target >= nums[s] && target < nums[m])
                    e = m - 1;
                else
                    s = m + 1;
            }
            // Right part sorted
            else {
                if (target > nums[m] && target <= nums[e])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return false;
    }
};
