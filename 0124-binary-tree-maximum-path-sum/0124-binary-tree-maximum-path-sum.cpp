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
    int solve(TreeNode* node , int &maxsum){
        if(!node)return 0;
        int leftsum = max(0 , solve(node->left , maxsum));
        int rightsum = max(0 , solve(node->right , maxsum));
        int currentmax = node->val + leftsum + rightsum;
        maxsum = max(maxsum , currentmax);
        return node->val + max(leftsum , rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(root , maxsum);
        return maxsum;
    }
};