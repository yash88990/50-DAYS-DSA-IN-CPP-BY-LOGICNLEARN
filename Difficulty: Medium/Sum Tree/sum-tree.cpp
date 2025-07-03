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
      int sum = leftans.second + rightans.second;
      if(root->data == sum){
          return {true , sum + root->data};
      }else return {false, 0};
  }
    bool isSumTree(Node* root) {
        // Your code here
        return solve(root).first;
    }
};