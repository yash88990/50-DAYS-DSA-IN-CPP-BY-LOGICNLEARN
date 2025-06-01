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
    pair<Node *, Node *> splitList(Node *head) {
        if (!head || head->next == head)
            return {head, nullptr};

        Node* slow = head;
        Node* fast = head;

        // Move slow and fast to find midpoint
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* firstHalf = head;
        Node* secondHalf = slow->next;

        // Make first half circular
        slow->next = firstHalf;

        // Make second half circular
        Node* temp = secondHalf;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = secondHalf;

        return {firstHalf, secondHalf};
    }
};


