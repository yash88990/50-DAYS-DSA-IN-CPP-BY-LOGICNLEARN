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
        Node* tail = head;
        while(tail->next)tail = tail->next;
        tail->next = head;
        head->prev = tail;
        for(int count = 1 ; count <= p; count++){
            head = head->next;
            tail =tail->next;
        }
        tail->next = NULL;
        head ->prev = NULL;
        return head;
        
    }
};

















