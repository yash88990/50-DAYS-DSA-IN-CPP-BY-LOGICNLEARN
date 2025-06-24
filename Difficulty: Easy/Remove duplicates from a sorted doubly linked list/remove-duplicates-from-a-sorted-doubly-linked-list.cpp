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
        
        if(!head || !head->next)return head;
        Node* curr = head;
        Node* prev = NULL;
        while(curr && curr->next){
            if(curr->data == curr->next->data){
                
                if(curr == head)head = curr->next;
                
                Node* nextNode = curr->next;
                
                
                nextNode->prev = prev;
                
                if(prev) prev->next = nextNode;
                Node* deletenode = curr;
                curr = curr->next;
                delete deletenode;
                
                
                
            }else{
                prev = curr;
                curr = curr->next;
                
            }
        }
        return head;
    }
};









