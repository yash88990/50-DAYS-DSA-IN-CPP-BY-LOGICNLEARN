class Solution {
  public:
  int setBits(int n) {
        // Write Your Code here
        int count =0;
        while( n  != 0){
            if(n & 1)count++;
            n = n >> 1;
            
        }
        return count;
        
    }
    int countBitsFlip(int a, int b) {
        // code here
        int c = a ^ b;
        int ans = setBits(c);
        return ans;
    }
};