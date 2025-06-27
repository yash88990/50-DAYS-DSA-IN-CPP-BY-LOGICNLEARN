/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        if(!head || head->next == head)return {head , NULL};
        Node* slow = head  , *fast = head;
        //find middle
        while(fast->next != head && fast->next->next != head){
            slow = slow->next;
            fast = fast->next->next;
        }
        //make two starting point
        Node* firsthalf = head;
        Node* secondhalf = slow->next;
        //make fisrt haslf circular
        slow->next = firsthalf;
        //make second half as circular
        Node* temp = secondhalf;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = secondhalf;
        
        
        return {firsthalf , secondhalf};
        
        
        
        
    }
};









