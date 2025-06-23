class Solution {
public:
    unordered_map<string, int> subtreeCounter;  // Used for counting occurrences of subtrees.
    vector<TreeNode*> duplicateSubtrees;        // Stores the roots of duplicate subtrees.

    // Function to find all duplicate subtrees in a binary tree.
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverseAndSerialize(root);
        return duplicateSubtrees;
    }

    // Helper function to perform DFS traversal and serialize each subtree.
    string traverseAndSerialize(TreeNode* node) {
        if (!node) return "#";  // Use "#" to represent null pointers.

        // Serialize the current subtree rooted at node.
        string serialization = to_string(node->val) + "," + traverseAndSerialize(node->left) + "," + traverseAndSerialize(node->right);

        // Increment the count for this serialized subtree.
        ++subtreeCounter[serialization];

        // If this is the second time we've seen this subtree, add it to the answer.
        if (subtreeCounter[serialization] == 2) {
            duplicateSubtrees.push_back(node);
        }

        // Return the serialization of this subtree.
        return serialization;
    }
};