// User function Template for C++

/*struct Node
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
    Node* findFirstNode(Node* head) {
        // your code here
        if(!head || !head->next)return head;
        Node* slow = head , *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    fast = fast->next;
                    slow = slow->next;
                    
                }
                return slow;
            }
        }
        return NULL;
    }
};