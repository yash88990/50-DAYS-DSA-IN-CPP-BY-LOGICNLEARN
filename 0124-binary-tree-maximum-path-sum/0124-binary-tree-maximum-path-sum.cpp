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
    int solve(TreeNode* node , int &maxSum){
        if(!node)return 0;
        int leftMax = max(0 , solve(node->left , maxSum));
        int rightMax = max( 0 , solve(node->right , maxSum));
        int currentMax = node->val + leftMax + rightMax;
        maxSum = max(maxSum , currentMax);
        return node->val + max(leftMax , rightMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(root , maxsum);
        return maxsum;
    }
};