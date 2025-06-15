/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        if(!head && !head->next)return head;
        Node* curr = head;
        while(curr && curr->next){
            if(curr->data == curr->next->data){
                Node* nextNode = curr->next->next;
                delete curr->next;
                curr->next = nextNode;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};