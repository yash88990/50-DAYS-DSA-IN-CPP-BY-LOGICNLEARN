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
    void solve(TreeNode* root , vector<int>&ans){
        if(!root)return;
         //node
        ans.push_back(root->val);
        //left
        solve(root->left , ans);
        //right
        solve(root->right , ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        //node left right
        vector<int> ans;
        solve(root ,ans);
        return ans;
    }
};