/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        struct Node* temp = head;
        struct Node* pre = NULL;
       while(temp!=NULL && temp->next!=NULL){
            if(temp->data == temp->next->data){
                if(temp == head){
                    head = temp->next;
                }
                temp->next->prev = pre;
                if(pre!=NULL){
                    pre->next = temp->next;
                }
                struct Node* curr = temp;
                temp = temp->next;
                delete curr;
            }
            else{
                pre = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};