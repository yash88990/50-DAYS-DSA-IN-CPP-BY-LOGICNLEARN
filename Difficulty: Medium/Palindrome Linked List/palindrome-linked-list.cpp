/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
public:
    // Helper function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    // Helper function to find the middle of the linked list
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to check whether the list is palindrome
    bool isPalindrome(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // Empty list or single node is a palindrome
        }
        
        // Step 1: Find the middle of the linked list
        Node* middle = findMiddle(head);
        
        // Step 2: Reverse the second half of the linked list
        Node* secondHalfStart = reverseList(middle);
        
        // Step 3: Compare the first and second halves
        Node* firstHalfStart = head;
        Node* secondHalf = secondHalfStart;
        while (secondHalf != nullptr) {
            if (firstHalfStart->data != secondHalf->data) {
                // Step 4 (Optional): Reverse the second half back to restore the list (if needed)
                reverseList(secondHalfStart);
                return false; // Not a palindrome
            }
            firstHalfStart = firstHalfStart->next;
            secondHalf = secondHalf->next;
        }
        
        // Step 4 (Optional): Restore the second half back to the original order
        reverseList(secondHalfStart);
        
        return true; // The linked list is a palindrome
    }
};


