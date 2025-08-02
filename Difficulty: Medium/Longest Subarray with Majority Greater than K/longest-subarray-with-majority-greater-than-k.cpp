
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> first_occurrence; // prefix_sum -> first index
        int max_len = 0;
        int prefix_sum = 0;

        for (int i = 0; i < n; i++) {
            // Convert to +1 or -1 based on condition
            int val = (arr[i] > k) ? 1 : -1;
            prefix_sum += val;

            if (prefix_sum > 0) {
                // Entire subarray from 0 to i is valid
                max_len = i + 1;
            } else {
                // Check if prefix_sum - 1 was seen before
                if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }

            // Store first occurrence of this prefix sum
            if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
                first_occurrence[prefix_sum] = i;
            }
        }

        return max_len;
    }
};


