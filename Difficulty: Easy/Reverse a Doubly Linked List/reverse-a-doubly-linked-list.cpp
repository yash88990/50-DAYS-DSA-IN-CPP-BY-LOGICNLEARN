/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
         if(!head || head->next == NULL) return head;
        
        Node* curr = head , *temp = NULL;
        while(curr != NULL){
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        
        if(temp != NULL){
            head = temp->prev;
        }
        return head;
    }
};