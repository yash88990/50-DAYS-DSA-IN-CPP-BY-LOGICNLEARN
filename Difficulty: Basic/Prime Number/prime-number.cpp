class Solution {
  public:
    bool isPrime(int n) {
        if (n <= 1) return false;  // base cases
        return checkDivisor(n, 2);
    }

  private:
    bool checkDivisor(int n, int i) {
        if (i * i > n) return true;     // no divisor found till sqrt(n)
        if (n % i == 0) return false;   // found a divisor
        return checkDivisor(n, i + 1);  // try next
    }
};

