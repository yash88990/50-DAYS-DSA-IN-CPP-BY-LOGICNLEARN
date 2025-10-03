class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int count = 0;
        int num = n;
        while(n != 0){
            int digit = n % 10;
            if( digit != 0 && num % digit == 0)count++;
            n /= 10;
        }
        return count;
        
    }
};