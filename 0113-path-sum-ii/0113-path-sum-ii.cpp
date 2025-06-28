
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, allPaths);
        return allPaths;
    }
private:
    void dfs(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        if (!node)     return;
        remainingSum -= node->val;
        currentPath.push_back(node->val);
        if (!node->left && !node->right && remainingSum == 0) {
            allPaths.push_back(currentPath);
        }
        dfs(node->left, remainingSum, currentPath, allPaths);
        dfs(node->right, remainingSum, currentPath, allPaths);
        currentPath.pop_back();
    }
};
