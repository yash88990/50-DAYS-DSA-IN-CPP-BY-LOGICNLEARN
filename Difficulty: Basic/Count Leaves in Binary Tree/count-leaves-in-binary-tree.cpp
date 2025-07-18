/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    void inorder(Node* root , int &count){
        if(root == NULL)return ;
        inorder(root->left , count);
        if(!root->left && !root->right) count++;
        inorder(root->right , count);
    }
    int countLeaves(Node* root) {
        // write code here
        if(!root)return 0;
        int count = 0;
        inorder(root , count);
        return count;
    }
};