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
        queue<Node* > q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(!front->left && !front->right)count++;
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        return count;
    }
};