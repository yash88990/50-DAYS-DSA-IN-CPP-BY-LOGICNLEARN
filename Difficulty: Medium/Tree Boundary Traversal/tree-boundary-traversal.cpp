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
    void traverseleft(Node* root , vector<int> &ans){
        if(!root || !root->left && !root->right)return ;
        ans.push_back(root->data);
        if(root->left)traverseleft(root->left , ans);
        else traverseleft(root->right , ans);
    }
    void traverseleaf(Node* root , vector<int> &ans){
        if(!root)return;
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        traverseleaf(root->left , ans);
        traverseleaf(root->right , ans);
    }
    void traverseright(Node* root , vector<int>&ans){
        if(!root)return ;
        if(!root->left && !root->right)return;
        if(root->right)traverseright(root->right , ans);
        else traverseright(root->left  , ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(!root)return ans;
        ans.push_back(root->data);
        traverseleft(root->left , ans);
        traverseleaf(root->left , ans);
        traverseleaf(root->right , ans);
        traverseright(root->right , ans);
        return ans;
    }
};