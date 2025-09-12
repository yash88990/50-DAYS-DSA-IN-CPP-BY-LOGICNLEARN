// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
    if (n == 1)
        return 0;

    // Sort the array
    sort(arr.begin(), arr.end());

    // Initialize the answer with the difference between the original max and min values
    int minHeight = arr[0];
    int maxHeight = arr[n - 1];
    int result = maxHeight - minHeight;

    // Iterate through the array and calculate the new min and max possible heights
    for (int i = 1; i < n; i++) {
        // Ignore if subtracting K results in a negative height
        if (arr[i] - k < 0) continue;

        // The minimum value after modifying the heights
        int newMin = min(arr[0] + k, arr[i] - k);
        // The maximum value after modifying the heights
        int newMax = max(arr[i - 1] + k, arr[n - 1] - k);

        // Update the result with the minimum difference found so far
        result = min(result, newMax - newMin);
    }

    return result;
    }
};
