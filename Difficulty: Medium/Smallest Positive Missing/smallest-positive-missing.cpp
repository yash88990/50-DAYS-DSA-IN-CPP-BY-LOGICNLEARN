



class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Segregate positive numbers and negatives
        int j = 0; // Pointer for positive numbers
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        
        // Now the first `j` elements are non-positive, and the rest are positive
        
        // Step 2: Use the positive part as a hash table
        for (int i = j; i < n; ++i) {
            int val = abs(arr[i]);
            if (val - 1 < n - j && arr[val - 1 + j] > 0) {
                arr[val - 1 + j] = -arr[val - 1 + j];
            }
        }
        
        // Step 3: Find the first positive index in the positive segment
        for (int i = j; i < n; ++i) {
            if (arr[i] > 0) {
                return i - j + 1;
            }
        }
        
        // If all indices are marked, the missing number is `n - j + 1`
        return n - j + 1;
    }
};



