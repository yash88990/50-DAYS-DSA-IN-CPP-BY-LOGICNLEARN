class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int cnt = 0;
        int num = n;
        while(num > 0){
            int digit = num % 10 ;
            if( digit != 0 && n % digit == 0 )cnt++;
            num /= 10;
        }
        return cnt;
    }
};