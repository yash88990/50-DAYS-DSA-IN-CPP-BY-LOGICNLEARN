/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/


class Solution {
public:
    unordered_map<string, int> subtreeCounts;
    bool foundDuplicate = false;

    string serializeTree(Node* node) {
        if (!node) {
            return "#";
        }

        string left_serialized = serializeTree(node->left);
        string right_serialized = serializeTree(node->right);

        string s = to_string(node->data) + "," + left_serialized + "," + right_serialized;

        if ((left_serialized != "#" || right_serialized != "#") && subtreeCounts[s] >= 1) {
            foundDuplicate = true;
        }
        
        subtreeCounts[s]++;

        return s;
    }

    int dupSub(Node *root) {
        subtreeCounts.clear();
        foundDuplicate = false;

        serializeTree(root);

        return foundDuplicate ? 1 : 0;
    }
};
