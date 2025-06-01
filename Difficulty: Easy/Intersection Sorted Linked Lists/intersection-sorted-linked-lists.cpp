/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* dummy = new Node(0);  // Dummy head for the result list
        Node* tail = dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data == head2->data) {
                // Add to result and move both pointers
                tail->next = new Node(head1->data);
                tail = tail->next;
                head1 = head1->next;
                head2 = head2->next;
            } else if (head1->data < head2->data) {
                head1 = head1->next;
            } else {
                head2 = head2->next;
            }
        }

        return dummy->next;
    }
};
