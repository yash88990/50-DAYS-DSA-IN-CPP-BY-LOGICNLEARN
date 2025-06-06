// User function Template for C++

class Solution {
  public:
    void solve(stack<int> &s, int x){
        //base case 
        if(s.empty()){
            s.push(x);
            return;
        }
        int temp = s.top();
        s.pop();
        //recc
        solve(s , x);
        s.push(temp);
    }
    stack<int> insertAtBottom(stack<int> st, int x) {
        solve(st , x);
        return st;
    }
};