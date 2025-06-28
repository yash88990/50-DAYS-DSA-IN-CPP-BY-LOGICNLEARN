class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        // Queue stores pairs of node and its position index
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = left;  // initialize right to left initially
            
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize index to prevent overflow
                index -= left;
                right = index;

                if (node->left) q.push({node->left, 2 * index});
                if (node->right) q.push({node->right, 2 * index + 1});
            }

            maxWidth = max(maxWidth, (int)(right + 1));
        }

        return maxWidth;
    }
};
