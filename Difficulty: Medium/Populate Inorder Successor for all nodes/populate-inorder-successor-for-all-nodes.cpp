/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* nextNode = NULL;

    void populateNext(Node *root) {
        if (!root) return;

        // Reverse inorder traversal: right -> root -> left
        populateNext(root->right);

        // Set current node's next to the previously visited node
        root->next = nextNode;

        // Update the nextNode to current node
        nextNode = root;

        // Continue with left subtree
        populateNext(root->left);
    }
};
