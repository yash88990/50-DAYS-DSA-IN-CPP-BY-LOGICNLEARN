class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int remainingSum) {
            if (!node) return;
            
            remainingSum -= node->val;
            currentPath.push_back(node->val);
            
            if (!node->left && !node->right && remainingSum == 0) {
                allPaths.push_back(currentPath);
            }
            
            dfs(node->left, remainingSum);
            dfs(node->right, remainingSum);
            
            currentPath.pop_back();
        };
        
        dfs(root, targetSum);
        return allPaths;
    }
};