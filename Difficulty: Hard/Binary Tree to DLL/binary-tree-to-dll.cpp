/* Structure for tree and linked list

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:

    // Step 1: Store inorder traversal in a vector
    void inorderStore(Node* root, vector<Node*>& nodes) {
        if (!root) return;
        inorderStore(root->left, nodes);
        nodes.push_back(root);
        inorderStore(root->right, nodes);
    }

    // Step 2: Convert the vector to doubly linked list
    Node* bToDLL(Node* root) {
        if (!root) return nullptr;

        vector<Node*> nodes;
        inorderStore(root, nodes);

        // Connect nodes to form DLL
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i]->left = (i == 0) ? nullptr : nodes[i - 1];
            nodes[i]->right = (i == nodes.size() - 1) ? nullptr : nodes[i + 1];
        }

        // Head of the DLL is the first node in inorder traversal
        return nodes[0];
    }
};
