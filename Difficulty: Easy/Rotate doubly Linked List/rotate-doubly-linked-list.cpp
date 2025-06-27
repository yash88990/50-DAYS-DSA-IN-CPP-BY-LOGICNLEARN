/*
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

        // code here..
        if(!head)return head;
        Node* tail = head;
        while(tail->next)tail = tail->next;
        //connect them
        tail->next = head;
        head->prev = tail;
        //move head and tail pointer by p times
        for(int i =0 ;i < p ; i++){
            head = head->next;
            tail= tail->next;
        }
        //break the circula loop
        tail->next = NULL;
        head->prev = NULL;
        
        return head;
        
        
        
    }
};












