/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* compute(Node* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Traverse and remove smaller nodes
        Node* curr = head;
        int maxVal = curr->data;
        while (curr && curr->next) {
            if (curr->next->data < maxVal) {
                // Remove the node
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxVal = curr->data;
            }
        }

        // Step 3: Reverse the list again to restore order
        head = reverse(head);
        return head;
    }
};
