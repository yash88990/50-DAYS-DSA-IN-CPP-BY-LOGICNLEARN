/* A binary tree node has data, pointer to left child
   and a pointer to right child

/*
struct Node
{
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        Node* current = root;

        while (current) {
            if (!current->left) {
                result.push_back(current->data);
                current = current->right;
            } else {
                struct Node* pre = current->left;
                while (pre->right && pre->right != current) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    pre->right = current;
                    result.push_back(current->data);
                    current = current->left;
                } else {
                    pre->right = nullptr;
                    current = current->right;
                }
            }
        }
        return result;
    }
};
