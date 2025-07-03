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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        if(!p || !q)return false;
        bool leftans = isSameTree(p->left , q->left);
        bool rightans = isSameTree(p->right , q->right);
        bool samedata = p->val == q->val;
        if(leftans && rightans && samedata)return true;
        else return false;
    }
};