/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    private:
    int solve(Node* node){
        if(node == NULL)return 0;
        int leftsum = solve(node->left);
        int rightsum = solve(node->right);
        int origianaldata = node->data;
        node->data =  leftsum + rightsum;
        return origianaldata + leftsum + rightsum;
    }
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        // Your code here
        solve(node);
    }
};