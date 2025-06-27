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
        vector<vector<int>>ans;
        if(!root)return ans;
        // hd , level , list od nodes
        map<int,map<int,vector<int>>> nodes;
        // node hd level
        queue<pair<TreeNode* , pair<int,int>>> q;
        q.push(make_pair(root , make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp = q.front();
            q.pop();
            TreeNode* front = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            nodes[hd][level].push_back(front->val);
            //left ja reh :- hd - 1
            if(front->left)q.push(make_pair(front->left , make_pair(hd - 1 , level + 1)));
            //right jaye :- hd + 1
            if(front->right)q.push(make_pair(front->right , make_pair(hd + 1 ,level+1)));
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