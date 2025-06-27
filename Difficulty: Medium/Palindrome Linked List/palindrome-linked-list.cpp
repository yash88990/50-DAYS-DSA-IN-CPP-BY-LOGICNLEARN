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
    Node* findmiddle(Node* head){
        if(!head)return NULL;
        Node* slow = head , *fast = head;
        while(fast && fast->next){
            fast = fast->next->next ;
            slow = slow->next;
        }
        return slow;
    }
    Node* reverselist(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            
        }
        return prev;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        if(!head || !head->next)return head;
        Node* middle = findmiddle(head);
        Node* secondhalfstart = reverselist(middle);
        Node* firsthalfstart = head;
        Node* secondhalf = secondhalfstart;
        while(secondhalf){
            if(firsthalfstart ->data != secondhalf->data){
                return false;
            }
            firsthalfstart = firsthalfstart->next;
            secondhalf = secondhalf->next;
        }
        return true;
    }
};