// User function Template for C++

class Solution {
  public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        // code here
        for(int i = 0 ; i <= n ; i++){
            if(pow(2,i) == n)return true;
            
        }
        return false;
    }
};