// User function Template for C++
class Solution {
  public:
    int findSize(Node *head) {
        // Code Here
        int count = 0;
        Node* curr = head;
        while(curr){
            curr = curr->next;
            count++;
        }
        return count;
    }
};