/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
      Node* nextNode = NULL;

    void populateNext(Node *root) {
        // code here
        if(!root)return;
        //right
        populateNext(root->right);
        //node
        root->next = nextNode;
        nextNode = root;
        populateNext(root->left);
        
        
    }
};