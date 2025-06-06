class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '[')stk.push(ch);
            else{
                if(!stk.empty()){
                    char top = stk.top();
                    if((ch == ')'  && top == '(') || (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')){
                              stk.pop();
                       }else{
                    return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(stk.empty())return true;
        else return false;
    }
};