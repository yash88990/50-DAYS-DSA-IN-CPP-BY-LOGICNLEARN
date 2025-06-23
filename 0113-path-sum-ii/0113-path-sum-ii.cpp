
class Solution {
public:
    // Main function to find all paths that sum to the target.
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths; // Stores all paths that sum to targetSum.
        vector<int> currentPath; // Holds the current path being evaluated.

        // Helper function to perform DFS on the tree
        function<void(TreeNode*, int)> depthFirstSearch = [&](TreeNode* node, int remainingSum) {
            if (!node) // Base case: If the node is null, return.
                return;
          
            remainingSum -= node->val; // Subtract the node's value from the remaining sum.
            currentPath.emplace_back(node->val); // Add the current node's value to the path.

            // Check if it's a leaf node and the remaining sum is 0; if so, store the path.
            if (!node->left && !node->right && remainingSum == 0) {
                allPaths.emplace_back(currentPath);
            }

            // Continue searching in the left and right subtrees.
            depthFirstSearch(node->left, remainingSum);
            depthFirstSearch(node->right, remainingSum);

            // Backtrack: remove the last element before returning to the previous caller.
            currentPath.pop_back();
        };

        // Start the depth-first search with the original root and target sum.
        depthFirstSearch(root, targetSum);

        // Return all found paths after the search is complete.
        return allPaths;
    }
};