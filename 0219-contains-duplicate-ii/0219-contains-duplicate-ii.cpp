#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            // If duplicate found in window, return true
            if (window.find(nums[i]) != window.end()) {
                return true;
            }

            // Add current element to the window
            window.insert(nums[i]);

            // Maintain window size <= k
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};
