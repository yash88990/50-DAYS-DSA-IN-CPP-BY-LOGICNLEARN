/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/


class Solution {
public:
    unordered_map<Node*, Node*> parentMap;
    Node* targetNodePointer = nullptr;

    void findParentsAndTarget(Node* node, Node* parent, int target_val) {
        if (!node) {
            return;
        }
        parentMap[node] = parent;

        if (node->data == target_val) {
            targetNodePointer = node;
        }

        findParentsAndTarget(node->left, node, target_val);
        findParentsAndTarget(node->right, node, target_val);
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        parentMap.clear();
        targetNodePointer = nullptr;
        findParentsAndTarget(root, nullptr, target);

        vector<int> result;
        if (!targetNodePointer) {
            return result;
        }

        queue<pair<Node*, int>> q;
        unordered_set<Node*> visited;

        q.push({targetNodePointer, 0});
        visited.insert(targetNodePointer);

        while (!q.empty()) {
            Node* curr_node = q.front().first;
            int curr_dist = q.front().second;
            q.pop();

            if (curr_dist == k) {
                result.push_back(curr_node->data);
                continue;
            }

            if (curr_node->left && visited.find(curr_node->left) == visited.end()) {
                q.push({curr_node->left, curr_dist + 1});
                visited.insert(curr_node->left);
            }
            if (curr_node->right && visited.find(curr_node->right) == visited.end()) {
                q.push({curr_node->right, curr_dist + 1});
                visited.insert(curr_node->right);
            }
            Node* parent = parentMap[curr_node];
            if (parent && visited.find(parent) == visited.end()) {
                q.push({parent, curr_dist + 1});
                visited.insert(parent);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
