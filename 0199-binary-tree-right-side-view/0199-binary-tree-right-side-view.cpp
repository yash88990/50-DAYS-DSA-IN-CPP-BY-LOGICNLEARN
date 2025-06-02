
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result; // If the tree is empty, return empty vector
        queue<TreeNode*> q;
        q.push(root); // Push the root node into the queue
        while (!q.empty()) {
            int levelSize = q.size(); // Get the number of nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // If it's the last node at this level, add its value to the result
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return result;
    }
};