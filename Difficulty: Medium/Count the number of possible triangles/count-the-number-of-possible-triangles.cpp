

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; // Not enough sides to form a triangle

        // Sort the array to simplify the triangle condition
        sort(arr.begin(), arr.end());
        int count = 0;

        // Fix the largest side (k), and use two pointers to find valid pairs (i, j)
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                // Check if arr[i] + arr[j] > arr[k]
                if (arr[i] + arr[j] > arr[k]) {
                    // All pairs between i and j are valid
                    count += (j - i);
                    --j;
                } else {
                    ++i;
                }
            }
        }

        return count;
    }
};




