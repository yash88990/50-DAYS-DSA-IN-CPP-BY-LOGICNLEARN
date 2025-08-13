class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i = 1 ; i * i * i <= n ; i++){
            if(n == pow(3,i))return true;
        }
        return false;
        
    }
};