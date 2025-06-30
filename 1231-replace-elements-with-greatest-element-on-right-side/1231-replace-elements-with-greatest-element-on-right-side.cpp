class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max_so_far = -1; // Last element should be -1

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            int temp = arr[i];      // Store current value
            arr[i] = max_so_far;    // Replace with max_so_far
            max_so_far = max(max_so_far, temp); // Update max
        }

        return arr;
    }
};
