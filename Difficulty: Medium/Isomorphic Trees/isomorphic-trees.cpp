/*Complete the function below
Node is as follows:
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


class Solution {
public:
    bool isIsomorphic(Node *root1, Node *root2) {
        if (!root1 && !root2) {
            return true;
        }

        if (!root1 || !root2 || root1->data != root2->data) {
            return false;
        }

        // Case 1: No flip
        bool noFlip = isIsomorphic(root1->left, root2->left) &&
                      isIsomorphic(root1->right, root2->right);

        // Case 2: Flip
        bool flip = isIsomorphic(root1->left, root2->right) &&
                    isIsomorphic(root1->right, root2->left);

        return noFlip || flip;
    }
};
