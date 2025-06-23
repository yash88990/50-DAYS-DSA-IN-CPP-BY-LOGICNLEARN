/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
private:
    pair<bool, long long> checkAndSum(Node* root) {
        if (!root) return {true, 0LL};
        if (!root->left && !root->right ) return {true, root->data};
        pair<bool, long long> left_result = checkAndSum(root->left);
        pair<bool, long long> right_result = checkAndSum(root->right);
        if (!left_result.first || !right_result.first)return {false, 0LL};
        long long children_subtrees_sum = left_result.second + right_result.second;
        if (root->data == children_subtrees_sum)
            return {true, root->data + children_subtrees_sum};
        else return {false, 0LL};
    }
public:
    bool isSumTree(Node* root) {
        return checkAndSum(root).first;
    }
};