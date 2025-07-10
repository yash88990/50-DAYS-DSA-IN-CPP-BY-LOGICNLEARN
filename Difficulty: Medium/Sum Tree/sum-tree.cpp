/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  pair<bool,int>solve(Node* root){
      if(!root)return {true, 0};
      if(!root->left && !root->right)return {true , root->data};
      pair<bool,int> leftans = solve(root->left);
      pair<bool,int> rightans = solve(root->right);
      if(!leftans.first || !rightans.first)return {false, 0};
      int sum = leftans.second + rightans.second;
      if(sum == root->data){
          return {true, sum + root->data};
      }else{
          return {false , 0};
      }
      
      
  }
    bool isSumTree(Node* root) {
        // Your code here
        return solve(root).first;
    }
};