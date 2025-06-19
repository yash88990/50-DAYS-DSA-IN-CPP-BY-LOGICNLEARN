class Solution {
  public:
    int findPosition(int n) {
        // Edge case: n must be > 0 and a power of 2
        if (n == 0 || (n & (n - 1)) != 0) {
            return -1;
        }

        int position = 1;
        while ((n & 1) == 0) {
            n >>= 1;
            position++;
        }
        
        return position;
    }
};
