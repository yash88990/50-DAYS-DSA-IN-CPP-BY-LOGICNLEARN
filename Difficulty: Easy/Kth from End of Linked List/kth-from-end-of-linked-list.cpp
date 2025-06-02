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
  public:
    int getCount(struct Node* head) {

        // Code here
        int count = 0;
        Node* curr = head;
        while(curr){
            curr = curr->next;
            count++;
        }
        return count;
    }
    
    int getKthFromLast(Node *head, int k) {
        // Your code here
        
        int length = getCount(head);
        if(k > length)return -1;
         Node* curr = head;
        int neededindex = length - k ;
        int count = 0;
        while(count < neededindex){
            curr = curr->next;
            count++;
        }
        return curr->data;
    }
};