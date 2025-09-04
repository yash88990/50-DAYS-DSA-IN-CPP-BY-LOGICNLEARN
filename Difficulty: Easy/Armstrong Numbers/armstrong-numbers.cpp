// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
         int sum = 0, originalnum = n;
        while(n > 0 ){
            int digit = n % 10;
            sum += pow(digit , 3);
            n /= 10;
        }
        if(sum == originalnum)return true;
        else return false;
    }
};