
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        while (current) {
            if (!current->left) {
                result.push_back(current->val);
                current = current->right;
            } else {
                TreeNode* pre = current->left;
                while (pre->right && pre->right != current) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};
