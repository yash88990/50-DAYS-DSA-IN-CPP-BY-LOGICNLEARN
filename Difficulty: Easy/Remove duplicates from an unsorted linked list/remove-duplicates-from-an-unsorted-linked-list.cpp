/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        if(!head)return NULL;
        unordered_set<int> seen;
        Node* prev = NULL , *curr = head;
        while(curr){
            if(seen.find(curr->data) != seen.end()){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else{
                seen.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};