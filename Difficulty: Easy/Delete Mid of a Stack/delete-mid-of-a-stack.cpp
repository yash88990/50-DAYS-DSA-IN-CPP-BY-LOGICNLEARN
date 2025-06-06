class Solution {
  public:
     void solve(stack<int>&s , int count , int n){
         //base case
         if(count  == n / 2){
             s.pop();
             return;
         }
         int temp = s.top();
         s.pop();
         //recc
         solve(s , count + 1 , n);
         s.push(temp);
     }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int count = 0;
        int n = s.size();
        solve(s , count , n);
    }
};