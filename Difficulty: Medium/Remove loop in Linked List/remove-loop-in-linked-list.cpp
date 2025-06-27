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
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        if(!head || !head->next)return ;
        Node* slow = head, *fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)break;
        }
        
        if(slow != fast)return;
        
        slow = head;
        
        if(slow == fast){
            //loop started from head
            while(fast->next != slow)fast = fast->next;
            
        }else{
            //loop started from somewhere else
            while(slow->next != fast->next){
                slow = slow->next;
                fast= fast->next;
            }
            
            
            
        }
        fast->next = NULL;
        
    }
};