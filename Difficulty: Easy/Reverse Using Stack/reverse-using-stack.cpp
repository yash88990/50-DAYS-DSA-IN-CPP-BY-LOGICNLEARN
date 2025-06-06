class Solution {
  public:
    string reverse(const string& s) {
        // code here
        stack<char> stk;
        for(char ch : s){
            stk.push(ch);
        }
        string ans = "";
        while(!stk.empty()){
            char ch = stk.top();
            ans.push_back(ch);
            stk.pop();
        }
        return ans;
    }
};