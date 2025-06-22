class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Map each node to its parent using BFS
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: BFS from target node up to distance k
        map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            if(level++ == k) break;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                // Explore neighbors: left, right, and parent
                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent.count(node) && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        // Step 3: Collect the result
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};