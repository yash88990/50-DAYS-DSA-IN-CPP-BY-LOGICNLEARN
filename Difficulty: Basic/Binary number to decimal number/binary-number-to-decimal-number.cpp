
class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
       int dec = 0 , power = 0;
       for(int i = b.length() - 1 ; i >= 0 ; i--){
           if(b[i] == '1'){
               dec += pow(2, power);
           }
           power++;
       }
       return dec;
    }
};

