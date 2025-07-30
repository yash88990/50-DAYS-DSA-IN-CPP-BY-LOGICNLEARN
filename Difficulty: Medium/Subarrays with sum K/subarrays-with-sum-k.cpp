class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> prefixSumCount; // Map to store prefix sums and their frequencies
    int prefixSum = 0;  // Cumulative sum
    int count = 0;      // Number of subarrays with sum equal to k

    for (int num : arr) {
        prefixSum += num;

        // Check if prefixSum is exactly k
        if (prefixSum == k) {
            count++;
        }

        // Check if (prefixSum - k) exists in the map
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - k];
        }

        // Update the map with the current prefixSum
        prefixSumCount[prefixSum]++;
    }

    return count;
    }
};