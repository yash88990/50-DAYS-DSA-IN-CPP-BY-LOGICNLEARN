class Solution {
  public:
     void solve(stack<int>& s , int size , int count){
         //base case 
         if(count == (size ) / 2 ){
             s.pop();
             return;
         }
         int temp = s.top();
         s.pop();
         //recc
         solve(s , size ,count + 1  );
         s.push(temp);
     }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int size = s.size();
        int count = 0;
        solve(s , size , count);
    }
};