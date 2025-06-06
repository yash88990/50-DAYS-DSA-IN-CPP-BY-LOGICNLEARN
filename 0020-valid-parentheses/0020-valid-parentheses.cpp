class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char i : s){
            if(i == '(' || i == '{' || i =='[')stk.push(i);
            else{
                //we found ) || } || ]
                if(!stk.empty()){
                    char top = stk.top();
                    if((i == ')' && top == '(' ) ||
                       (i == '}'  && top == '{' ) ||
                       (i == ']' && top == '[')
                    )stk.pop();
                    else return false;
                }else return false;

            }
            

        }
        if(stk.empty())return true;
            else return false;
    }
};