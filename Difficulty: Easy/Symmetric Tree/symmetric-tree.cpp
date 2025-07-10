/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
  bool solve(Node* p , Node* q){
      if(!p && !q)return true;
      if((p && !q) || (!p && q) || (p->data != q->data))return false;
      bool ans1 = solve(p->left , q->right);
      bool ans2 = solve(p->right , q->left);
      return ans1 && ans2;
  }
    bool isSymmetric(Node* root) {
        // Code here
        if(!root)return true;
        return solve(root->left , root->right);
    }
};