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
    TreeNode* solve(vector<int> &inorder , int instart , int inend ,vector<int>&postorder , int &index , unordered_map<int,int>& inMap){
        //baese case
        if(instart > inend)return NULL;
        int rootval = postorder[index--];
        TreeNode* root = new TreeNode(rootval);
        int rootindex = inMap[rootval];
        root->right = solve(inorder , rootindex + 1 , inend , postorder , index, inMap);
        root->left = solve(inorder , instart , rootindex - 1 , postorder , index , inMap);
        return root;

    }




    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for(int i = 0 ;i < inorder.size() ; i++){
            inMap[inorder[i]] = i;
        }
        int index = postorder.size() -1;
        return solve(inorder , 0 , inorder.size() - 1 , postorder , index  , inMap);
    }
};