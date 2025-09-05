class Solution {
public:
    int solve(int x, int n, int M) {
        if (n == 0) return 1;
        long long temp = solve(x, n / 2, M);

        // Cast to long long for the multiplication to prevent overflow
        temp = (temp * temp) % M;

        if (n % 2 == 0)
            return temp;
        else
            return ((long long)x * temp) % M;
    }
    
    int powMod(int x, int n, int M) {
        // code here
        return solve(x, n, M);
    }
};