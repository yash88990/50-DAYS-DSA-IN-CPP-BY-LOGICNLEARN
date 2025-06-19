class Solution {
  public:
    int countBitsFlip(int a, int b) {
        // code here
        int count=0;
        while(a>0 || b>0)
        {
            if(a%2!=b%2)
            count++;
            a=a/2;
            b=b/2;
        }
        return count;
    }
};