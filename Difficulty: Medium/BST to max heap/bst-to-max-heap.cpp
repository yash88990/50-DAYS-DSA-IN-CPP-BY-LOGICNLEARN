// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/


class Solution {
public:
    void inorderCollect(Node* root, vector<int>& values) {
        if (!root) {
            return;
        }
        inorderCollect(root->left, values);
        values.push_back(root->data);
        inorderCollect(root->right, values);
    }

    void postorderAssign(Node* root, vector<int>& values, int& index) {
        if (!root) {
            return;
        }
        postorderAssign(root->left, values, index);
        postorderAssign(root->right, values, index);
        root->data = values[index++];
    }

    void convertToMaxHeapUtil(Node* root) {
        if (!root) {
            return;
        }

        vector<int> values;
        inorderCollect(root, values);

        int index = 0;
        postorderAssign(root, values, index);
    }
};
