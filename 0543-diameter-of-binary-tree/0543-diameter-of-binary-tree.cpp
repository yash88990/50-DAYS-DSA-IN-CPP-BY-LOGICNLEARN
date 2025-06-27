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
    pair<int,int> solve(TreeNode* root){
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        int case1 =  left.first;
        int case2 = right.first;
        int case3 = left.second + right.second;
        pair<int,int> ans;
        ans.first = max(case1 , max(case2 , case3));
        ans.second = max(left.second , right.second) + 1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }

};