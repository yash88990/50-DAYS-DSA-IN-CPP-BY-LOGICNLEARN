// User function Template for C++

class Solution {
  public:
    Node *moveToFront(Node *head) {
        // code here
        if(!head || !head->next)return head;
        Node* tail = head;
        while(tail->next->next){
            tail = tail->next;
        }
        tail->next->next = head;
         head = tail->next;
        tail->next = NULL;
       
        return head;
    }
};