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
        pair<bool, long long> leftans = checkAndSum(root->left);
        pair<bool, long long> rightans = checkAndSum(root->right);
        if (!leftans.first || !rightans.first)return {false, 0LL};
        long long children_subtrees_sum = leftans.second + rightans.second;
        if (root->data == children_subtrees_sum)
            return {true, root->data + children_subtrees_sum};
        else return {false, 0LL};
    }
public:
    bool isSumTree(Node* root) {
        return checkAndSum(root).first;
    }
};