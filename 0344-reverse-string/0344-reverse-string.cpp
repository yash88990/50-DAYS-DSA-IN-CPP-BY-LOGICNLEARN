class Solution {
public:
    void solve(vector<char>& s , int start , int end){
        //base case
        if(start > end)return;
        //process
        swap(s[start] , s[end]);
        ///recc
        solve(s , start + 1 , end -1);
    }
    void reverseString(vector<char>& s) {
        solve(s , 0 , s.size() - 1);
    }
};