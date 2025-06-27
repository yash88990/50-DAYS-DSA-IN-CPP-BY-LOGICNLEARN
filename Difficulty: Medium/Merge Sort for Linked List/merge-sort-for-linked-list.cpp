/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* findmiddle(Node* head){
        if(!head)return NULL;
        Node* slow = head , *fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node* merge(Node* left , Node* right){
        if(!left)return right;
        if(!right)return left;
        Node* result = NULL;
        if(left->data <= right->data){
            result = left ;
            result->next = merge(left->next , right);
        }
        else{
            result = right ;
            result->next = merge(left , right->next);
        }
        return result;
    }
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next)return head;
        Node* mid = findmiddle(head);
        Node* rightHead = mid->next;
        mid->next = NULL;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);
        
        return merge(left , right);
    }
};