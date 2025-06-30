/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node* root , vector<int> &inorderarr){
      if(!root)return;
      inorder(root->left , inorderarr);
      inorderarr.push_back(root->data);
      inorder(root->right , inorderarr);
  }
    int getCount(Node *root, int l, int h) {
        // your code here
        vector<int>inorderarr;
        inorder(root , inorderarr);
        int count = 0;
        for(int i = 0 ; i < inorderarr.size() ; i++){
            if(inorderarr[i] >= l && inorderarr[i] <= h)count++;
        }
        return count;
    }
};






