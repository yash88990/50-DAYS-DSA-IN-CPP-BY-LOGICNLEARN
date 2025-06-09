class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;  // Start from prefix 1
        k--;  // Decrease k by 1 because we start with 1 being the first number
        
        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);  // Count steps between curr and curr+1
            if (steps <= k) {
                // If the number of steps is less than k, move to the next prefix
                k -= steps;
                curr++;
            } else {
                // Otherwise, go deeper into the current prefix
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
    
    // Count how many numbers are there between curr and next within the range [1, n]
    long long countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};