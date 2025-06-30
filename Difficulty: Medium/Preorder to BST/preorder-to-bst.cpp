// User function template in C++
// #include <climits>
// #include <cstdlib>

// typedef struct Node {
//     int data;
//     struct Node *left, *right;
// } Node;

// // A utility function to create a new tree node
// Node* newNode(int data) {
//     Node* temp = (Node*)malloc(sizeof(Node));
//     temp->data = data;
//     temp->left = temp->right = NULL;
//     return temp;
// }

class Solution {
  public:
    // Helper function to build BST using preorder with bounds
    Node* constructBST(int pre[], int& index, int size, int minVal, int maxVal) {
        if (index >= size) return NULL;

        int val = pre[index];

        // Current value must lie within valid range
        if (val < minVal || val > maxVal)
            return NULL;

        // Create current node using helper
        Node* root = newNode(val);
        index++;

        // Recur for left subtree with updated upper bound
        root->left = constructBST(pre, index, size, minVal, val - 1);

        // Recur for right subtree with updated lower bound
        root->right = constructBST(pre, index, size, val + 1, maxVal);

        return root;
    }

    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        int index = 0;
        return constructBST(pre, index, size, INT_MIN, INT_MAX);
    }
};
