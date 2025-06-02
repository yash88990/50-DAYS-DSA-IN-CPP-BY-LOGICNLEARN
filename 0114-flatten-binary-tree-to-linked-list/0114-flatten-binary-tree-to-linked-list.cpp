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
#include <stack>
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* current = stack.top();
            stack.pop();

            if (current->right) {
                stack.push(current->right);
            }
            if (current->left) {
                stack.push(current->left);
            }

            if (!stack.empty()) {
                current->right = stack.top();
            }

            current->left = nullptr;
        }
        
    }
};