class Solution {
public:
    // Main function to find all paths that sum to targetSum
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;      // Stores all paths that sum to targetSum.
        vector<int> currentPath;           // Holds the current path being evaluated.
        
        // Call the helper DFS function to start the traversal
        dfs(root, targetSum, currentPath, allPaths);
        
        return allPaths;
    }

private:
    // Helper function for Depth First Search traversal
    void dfs(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        // Base case: if the node is null, return
        if (!node) {
            return;
        }
        
        // Subtract the current node's value from the remaining sum
        remainingSum -= node->val;
        // Add the current node's value to the current path
        currentPath.push_back(node->val);
        
        // If it's a leaf node and the remaining sum is zero, a valid path is found
        if (!node->left && !node->right && remainingSum == 0) {
            allPaths.push_back(currentPath);
        }
        
        // Recursively call DFS for the left child
        dfs(node->left, remainingSum, currentPath, allPaths);
        // Recursively call DFS for the right child
        dfs(node->right, remainingSum, currentPath, allPaths);
        
        // Backtrack: remove the current node's value from the path as we return up the tree
        currentPath.pop_back();
    }
};