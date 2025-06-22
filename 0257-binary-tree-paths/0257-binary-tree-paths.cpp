class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;

        // Append current node value
        if (!path.empty()) path += "->";
        path += to_string(node->val);

        // If leaf node, store the path
        if (!node->left && !node->right) {
            res.push_back(path);
            return;
        }

        // Recurse on left and right children
        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};
