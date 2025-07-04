/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        //hd level nodes
        map<int , map<int,vector<int>>> nodes;
        //node hd level
        queue<pair<TreeNode* , pair<int,int>>>q;
        q.push(make_pair(root , make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode* , pair<int,int>> curr = q.front();
            q.pop();
            TreeNode* front = curr.first;
            int hd = curr.second.first;
            int lvl = curr.second.second;
            nodes[hd][lvl].push_back(front->val);
            if(front->left)q.push(make_pair(front->left , make_pair(hd -1 , lvl + 1)));
            if(front->right)q.push(make_pair(front->right , make_pair(hd +1  , lvl + 1)));

        }


        for(auto i : nodes){
            vector<int>col;
            for(auto j : i.second){
                vector<int>temp = j.second;
                sort(temp.begin() , temp.end());
                col.insert(col.end() , temp.begin() , temp.end());

            }
            ans.push_back(col);
        }
        return ans;


    }
};