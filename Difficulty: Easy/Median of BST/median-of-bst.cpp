/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Step 1: Count nodes in the BST
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Step 2: Inorder traversal to find the median
void findInorderMedian(struct Node* root, int& count, int target1, int target2, int& val1, int& val2) {
    if (!root) return;

    findInorderMedian(root->left, count, target1, target2, val1, val2);

    count++;
    if (count == target1) val1 = root->data;
    if (count == target2) val2 = root->data;

    findInorderMedian(root->right, count, target1, target2, val1, val2);
}

// Main function to find median
float findMedian(struct Node *root) {
    int n = countNodes(root);

    int val1 = -1, val2 = -1;
    int count = 0;

    if (n % 2 == 1) {
        // Odd: pick the (n+1)/2-th node
        findInorderMedian(root, count, (n+1)/2, (n+1)/2, val1, val2);
        return (float)val1;
    } else {
        // Even: average of n/2-th and (n/2 + 1)-th nodes
        findInorderMedian(root, count, n/2, n/2 + 1, val1, val2);
        return (val1 + val2) / 2.0;
    }
}
