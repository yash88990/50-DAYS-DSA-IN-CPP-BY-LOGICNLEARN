/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
    int calculateAndModifySumTree(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_subtree_sum = calculateAndModifySumTree(node->left);
        int right_subtree_sum = calculateAndModifySumTree(node->right);
        int original_data = node->data;
        node->data = left_subtree_sum + right_subtree_sum;
        return original_data + left_subtree_sum + right_subtree_sum;
    }

public:
    void toSumTree(Node *node) {
        calculateAndModifySumTree(node);
    }
};
