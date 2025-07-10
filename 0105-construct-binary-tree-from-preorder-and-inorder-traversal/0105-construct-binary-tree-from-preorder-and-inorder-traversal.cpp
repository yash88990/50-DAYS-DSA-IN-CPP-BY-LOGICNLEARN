/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>&inorder , int instart , int inend , vector<int>&preorder , int &index  , unordered_map<int,int>&inmap ){
        //base case
        if(instart > inend)return NULL;
        int rootval = preorder[index++];
        int rootindex = inmap[rootval];
        TreeNode* root = new TreeNode(rootval);
        root->left = solve(inorder , instart , rootindex - 1 , preorder ,index, inmap);
        root->right = solve(inorder , rootindex + 1 , inend , preorder , index , inmap);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() ;
        int index = 0;
        unordered_map<int,int>inmap;
        for(int i = 0 ; i < n ; i++){
            inmap[inorder[i]] = i; 
        }
        return solve(inorder , 0 , n-1, preorder , index , inmap);
    }
};