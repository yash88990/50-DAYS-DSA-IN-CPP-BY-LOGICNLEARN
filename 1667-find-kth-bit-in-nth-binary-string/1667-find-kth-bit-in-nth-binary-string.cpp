class Solution {
public:
    char invert(char c) {
        return c == '0' ? '1' : '0';
    }

    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = len / 2 + 1;

        if (k == mid) return '1';
        else if (k < mid)
            return findKthBit(n - 1, k);
        else {
            int mirror = len - k + 1;
            return invert(findKthBit(n - 1, mirror));
        }
    }
};
