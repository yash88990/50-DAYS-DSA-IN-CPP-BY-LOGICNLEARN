class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> result(n, -1); // Initialize result with -1 for all elements
    stack<int> s; // Stack to store indices

    // Loop through the array twice to handle the circular nature
    for (int i = 0; i < 2 * n; i++) {
        int index = i % n; // Get the actual index in the array

        // For each element, keep popping from stack while elements are smaller
        while (!s.empty() && arr[index] > arr[s.top()]) {
            result[s.top()] = arr[index]; // Current element is the next greater for popped elements
            s.pop();
        }

        // Only push indices within the original array size
        if (i < n) {
            s.push(index);
        }
    }

    return result;
    }
};