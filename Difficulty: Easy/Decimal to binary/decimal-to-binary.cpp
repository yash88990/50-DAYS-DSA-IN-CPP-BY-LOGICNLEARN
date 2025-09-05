class Solution {
  public:
    string decToBinary(int n) {
        // code here
        if(n == 0 )return "0";
        string ans = "";
        while(n> 0){
            ans = to_string(n % 2)  + ans;
            n /= 2;
        }
        return ans;
    }
};