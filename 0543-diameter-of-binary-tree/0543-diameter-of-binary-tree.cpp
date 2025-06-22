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
    private:
     int height(TreeNode* root) {
        if(!root)return 0;
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left , right) + 1 ;
        return ans;
    }
    public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int case1 = diameterOfBinaryTree(root->left);
        int case2 = diameterOfBinaryTree(root->right);
        int case3 = height(root->left) + height(root->right) ;
        int ans = max(case1 , max(case2 , case3));
        return ans;
    }
};