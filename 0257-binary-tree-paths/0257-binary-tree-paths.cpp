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
    void dfs(TreeNode* root  , vector<string>&ans , string path){
        if(!root)return;
        //path ko stor karo
        if(!path.empty())path += "->";
        path += to_string(root->val);
        //if reach to leaf node stor in ans
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }
        //recc
        dfs(root->left , ans  , path);
        dfs(root->right , ans , path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        dfs(root , ans, "");
        return ans;
    }
};