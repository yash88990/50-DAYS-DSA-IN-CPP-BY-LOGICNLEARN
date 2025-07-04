// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countnodes(Node* tree){
        if(!tree)return 0;
        return 1 + countnodes(tree->left) + countnodes(tree->right);
    }
    
    bool completetree(Node* tree , int index , int totalnodes){
        if(!tree)return true;
        if(index >= totalnodes)return false;
        return completetree(tree->left , 2 * index+ 1 , totalnodes) &&
               completetree(tree->right , 2 * index + 2 , totalnodes);
    }
    
    bool heaporder(Node* tree){
        if(!tree)return true;
        if(!tree->left && !tree->right)return true;
        if(!tree->right)
             return (tree->data >= tree->left->data) && heaporder(tree->left);
        else{
            bool left = tree->data >= tree->left->data;
            bool right = tree->data >= tree->right->data;
            return left && right && heaporder(tree->left) && heaporder(tree->right);
        }
    }
    
    bool isHeap(Node* tree) {
        // code here
        int totalnodes = countnodes(tree);
        return completetree(tree , 0 , totalnodes) && heaporder(tree);
    }
};