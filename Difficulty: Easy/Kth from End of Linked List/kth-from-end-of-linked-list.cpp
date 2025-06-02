/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
    void reverselist(Node* &head){
        Node* curr = head , *prev = NULL;
        while(curr){
            Node* temp = curr->next;
            curr->next = prev ;
            prev = curr ;
            curr = temp;
        }
        head = prev;
        
    }
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        reverselist(head);
        Node* curr = head;
        int count = 1 ;
        while(count < k && curr ){
            curr = curr->next;
            count++;
        }
        if(curr)return curr->data;
        else return -1;
        
    }
};