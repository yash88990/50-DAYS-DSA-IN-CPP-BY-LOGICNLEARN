class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1); // keep removing the rightmost set bit
        }
        return right;
    }
};
