/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root , vector<int>&ans){
            if(!root)return;
           inorder(root->left , ans);
           ans.push_back(root->data);
           inorder(root->right , ans);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> bst1 , bst2;
        inorder(root1 , bst1);
        inorder(root2, bst2);
        
        vector<int>merged;
        
        for(int num : bst1)merged.push_back(num);
        for(int num : bst2)merged.push_back(num);
        
        sort(merged.begin() , merged.end());
        
        return merged;
    }
};