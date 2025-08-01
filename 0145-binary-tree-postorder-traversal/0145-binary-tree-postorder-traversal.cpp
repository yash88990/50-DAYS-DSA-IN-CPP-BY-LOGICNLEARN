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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*> s;
        TreeNode* curr = root , *lastvisited = NULL;
        while(curr || !s.empty()){
            if(curr){
                s.push(curr);
                curr = curr->left;
            }else{
                TreeNode* node = s.top();
                if(node->right && node->right != lastvisited){
                    curr = node->right;
                }else{
                    ans.push_back(node->val);
                    lastvisited = node;
                    s.pop();
                }
            }
        }
        return ans;
    }
};