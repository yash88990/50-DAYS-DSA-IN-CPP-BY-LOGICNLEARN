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
     int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left , right) + 1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int case1 =diameterOfBinaryTree(root->left);
        int case2 =diameterOfBinaryTree(root->right);
        int case3 = maxDepth(root->left) + maxDepth(root->right);
        int ans = max(case1 , max(case2 , case3));
        return ans;
    }

};