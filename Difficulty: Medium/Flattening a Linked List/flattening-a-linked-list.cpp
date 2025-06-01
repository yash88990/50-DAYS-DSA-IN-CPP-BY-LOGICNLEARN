/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
     Node* merge(Node* &a , Node* &b){
         if(!a)return b;
         if(!b)return a;
         
         Node* result;
         if(a->data < b->data){
             result = a;
             result->bottom = merge(a->bottom , b);
         }else{
             result = b ;
             result->bottom = merge(a , b->bottom);
         }
         result->next = NULL;
         return result;
     }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(!root || !root->next)return root;
        root->next = flatten(root->next);
        root = merge(root , root->next);
        return root;
        
    }
};