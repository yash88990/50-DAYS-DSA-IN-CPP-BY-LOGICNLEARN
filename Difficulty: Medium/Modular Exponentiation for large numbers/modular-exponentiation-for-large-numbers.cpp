class Solution {
  public:
    long long int solve(long long int x, long long int n, long long int M) {
        if (n == 0) return 1;

        long long int temp = solve(x, n / 2, M);
        temp = (temp * temp) % M;

        if (n % 2 == 0)
            return temp;
        else
            return (x % M * temp) % M;
    }

    long long int PowMod(long long int x, long long int n, long long int M) {
        return solve(x, n, M);
    }
};
