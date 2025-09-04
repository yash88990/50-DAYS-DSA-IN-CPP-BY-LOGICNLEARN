// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if( n < 2)return n;
        int prev1 = 1;
        int prev2 = 0;
        int cnt = 1;
        while(cnt < n){
            int next = prev1 + prev2;
            prev2 = prev1 ;
            prev1 = next ;
            cnt++;
        }
        return prev1;
        
        
    }
};