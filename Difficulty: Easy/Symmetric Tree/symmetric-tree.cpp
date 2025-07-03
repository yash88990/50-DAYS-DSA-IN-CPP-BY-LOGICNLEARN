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
bool solve(Node* root1, Node* root2)
    {
        if(!root1 && !root2) return true;
        
        if((!root1  || !root2) || (root1->data != root2->data))return false;
        
        bool check1= solve(root1->left,root2->right);
        bool check2= solve(root1->right,root2->left);
        
        return (check1 && check2);
        
    }
class Solution {
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if(!root) return true;
        
        return solve(root->left,root->right);
    }
};

