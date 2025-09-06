/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
     int countLoopNodes(Node* meetingPoint) {
        int count = 1;
        Node* current = meetingPoint;
        while (current->next != meetingPoint) {
            current = current->next;
            count++;
        }
        return count;
    }
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if (slow == fast) {
                return countLoopNodes(slow);
            }
        }

        return 0; // No loop
    }
};