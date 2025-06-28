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
    TreeNode* solve(vector<int> &preorder , int preStart , int preEnd ,vector<int>&inorder , int inStart , int inEnd , unordered_map<int,int>& inMap){
        //BASE case
        if(preStart > preEnd || inStart > inEnd)return NULL;
        //make root node
        int rootval = preorder[preStart];
        TreeNode* root = new TreeNode(rootval);
        //find index of root in inMap
        int inRoot = inMap[rootval];
        //divide into two subtree
        // .1 left wala 
        int numsleft = inRoot - inStart;
        //use recc 
        root->left = solve(preorder , preStart + 1 , preStart + numsleft , inorder , inStart , inRoot - 1, inMap);
        root->right = solve(preorder , preStart + numsleft + 1 , preEnd , inorder , inRoot + 1 , inEnd , inMap);
        return root;

    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //step 1 :- create a map for storing indices of inorder elements
        unordered_map<int,int> inMap;
        for(int i = 0 ; i < inorder.size() ; i++){
            inMap[inorder[i]] = i;
        }
        //define a recc function to build tree
        return solve(preorder , 0 , preorder.size() - 1 , inorder , 0 , inorder.size() -1 , inMap);
    }
};