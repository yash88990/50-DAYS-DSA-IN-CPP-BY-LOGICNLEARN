/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
class Solution {
  public:
    void removeLoop(Node* head) {
        Node *slow = head, *fast = head;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // No loop found
        if (slow != fast) return;

        // Step 2: Find start of loop
        slow = head;
        if (slow == fast) {
            // Loop starting from head
            while (fast->next != slow) fast = fast->next;
            fast->next = NULL;
        } else {
            // Loop starting somewhere else
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            // Step 3: Remove loop
            fast->next = NULL;
        }
    }
};


