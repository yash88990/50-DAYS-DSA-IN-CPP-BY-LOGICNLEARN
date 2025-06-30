class Solution {
public:
    TreeNode* buildtree(vector<int>& inorder, int instart, int inend, int &index, vector<int>& preorder, unordered_map<int,int> &inMap) {
        if(instart > inend) return NULL;
        int rootval = preorder[index++];
        // index++;
        int rootindex = inMap[rootval];
        TreeNode* root = new TreeNode(rootval);
        root->left = buildtree(inorder, instart, rootindex - 1, index, preorder, inMap);
        root->right = buildtree(inorder, rootindex + 1, inend, index, preorder, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        int index = 0;
        return buildtree(inorder, 0, inorder.size() - 1, index, preorder, inMap);
    }
};