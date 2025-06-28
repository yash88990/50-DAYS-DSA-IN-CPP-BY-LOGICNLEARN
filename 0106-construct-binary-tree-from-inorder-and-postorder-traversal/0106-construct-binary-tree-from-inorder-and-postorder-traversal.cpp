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
    TreeNode* solve(vector<int> &inorder , int instart , int inend ,vector<int>&postorder , int poststart  , int  postend , unordered_map<int,int>& inMap){
        //baese case
        if(instart > inend || poststart > postend)return NULL;
        int rootval = postorder[postend];
        TreeNode* root = new TreeNode(rootval);
        int rootindex = inMap[rootval];
        int leftsize = rootindex - instart;
        root->left = solve(inorder , instart , rootindex - 1 , postorder , poststart , poststart + leftsize  -1  , inMap);
        root->right = solve(inorder , rootindex + 1 , inend , postorder , poststart + leftsize , postend - 1 , inMap);
        return root;

    }




    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for(int i = 0 ;i < inorder.size() ; i++){
            inMap[inorder[i]] = i;
        }
        return solve(inorder , 0 , inorder.size() - 1 , postorder , 0 , postorder.size() -1  , inMap);
    }
};