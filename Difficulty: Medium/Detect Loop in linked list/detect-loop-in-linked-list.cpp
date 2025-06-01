// User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if(!head || !head->next)return false;
        Node* slow = head , *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)return true;
            
        }
        return false;
    }
};

