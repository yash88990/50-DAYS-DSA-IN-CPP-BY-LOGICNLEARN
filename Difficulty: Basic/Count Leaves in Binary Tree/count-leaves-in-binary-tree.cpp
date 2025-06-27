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
    int countLeaves(Node* root) {
        // write code here
        queue<Node*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(!curr->left && !curr->right)count++;
            if(curr->left)q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return count;
    }
};