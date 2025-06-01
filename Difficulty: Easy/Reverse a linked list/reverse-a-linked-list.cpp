/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev ;
            prev = curr;
            curr= next;
            
        }
        return prev;
    }
};

