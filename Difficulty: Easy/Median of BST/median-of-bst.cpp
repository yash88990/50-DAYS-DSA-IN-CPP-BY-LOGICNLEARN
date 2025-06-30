/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
int countnodes(Node* root){
    if(!root)return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}
void inorder(Node* root , vector<float>&arr){
    if(!root)return;
    inorder(root->left , arr);
    arr.push_back(root->data);
    inorder(root->right , arr);
}
float findMedian(struct Node *root) {
    // Code here
    int n = countnodes(root);
    vector<float>arr;
    inorder(root, arr);
    if( n % 2 == 0){
        float res = (arr[n/2] + arr[n/2 - 1 ]) / 2.0; 
        return res;
        
    }else{
        float res = arr[n/2];
        return res;
    }
}