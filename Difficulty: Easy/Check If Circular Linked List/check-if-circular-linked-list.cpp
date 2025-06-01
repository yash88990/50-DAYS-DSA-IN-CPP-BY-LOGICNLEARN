/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        if(!head )return tr;
        Node* slow = head , *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow =  slow->next;
            if(slow == fast)return true;
        }
        return false;
    }
};