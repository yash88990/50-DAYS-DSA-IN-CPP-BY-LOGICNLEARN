class Solution {
  public:
    string reverse(const string& S) {
        // code here
        //step 1 
        stack<char> stk;
        //pushing all char in stk
        for(char ch : S){
            stk.push(ch);
        }
        //removing all char from stk and store it i  sting
        string ans ="";
        while(!stk.empty()){
            char ch = stk.top();
            stk.pop();
            ans.push_back(ch);
        }
        return ans;
    }
};