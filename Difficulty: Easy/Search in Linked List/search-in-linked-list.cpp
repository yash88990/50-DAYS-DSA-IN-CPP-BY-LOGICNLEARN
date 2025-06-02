/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        Node* curr = head;
        while(curr){
            if(curr->data == key)return true;
            curr = curr->next;
        }
        return false;
    }
};
