/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/


class Solution {
public:
    bool check(Node *root) {
        if (!root) {
            return true;
        }

        queue<pair<Node*, int>> q;
        q.push({root, 0});

        int firstLeafLevel = -1;

        while (!q.empty()) {
            Node* curr_node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (!curr_node->left && !curr_node->right) { // It's a leaf node
                
                if (firstLeafLevel == -1) { // This is the first leaf we've encountered
                    firstLeafLevel = level;
                } else if (level != firstLeafLevel) { // Not all leaves are at the same level
                    return false;
                }
            } 
            
            
            else { // Not a leaf node, explore children
                if (curr_node->left) {
                    q.push({curr_node->left, level + 1});
                }
                if (curr_node->right) {
                    q.push({curr_node->right, level + 1});
                }
            }
        }
        return true;
    }
};
