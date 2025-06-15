/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
     Node*  reverse(Node* head){
         if(!head || !head->next)return head;
         Node* curr = head , *prev = NULL;
         while(curr){
             Node* temp = curr->next;
             curr->next = prev;
             prev = curr;
             curr = temp;
         }
         return prev;
     }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1 = reverse(num1);
        num2 = reverse(num2);
        int carry = 0;
        Node* curr = NULL;
        while(num1 || num2 || carry > 0){
            int val1 = (num1) ? num1->data : 0;
            int val2 = (num2) ? num2->data : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            Node* temp = new Node(sum % 10);
            temp->next = curr;
            curr = temp;
            
            if(num1)num1 = num1->next;
            if(num2)num2  = num2->next;
        }
        while(curr && curr->data == 0)curr = curr->next;
        return curr;
        
    }
};
















