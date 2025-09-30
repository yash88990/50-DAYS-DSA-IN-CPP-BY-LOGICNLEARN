class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int start = 0 , end = s.size()-1;
        while(start < end){
            if(s[start] != s[end])return false;
            else {
                start++;
                end--;
            }
        }
        return true;
    }
};