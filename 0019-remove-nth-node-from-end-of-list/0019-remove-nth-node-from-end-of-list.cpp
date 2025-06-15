/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // /step 1 count the total nodes
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
         if(n == count){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        //step 2 :- compute the position from starting 
        int pos = count - n;
        temp = head;
        int i = 1;
        while( i < pos ){
            temp = temp->next;
            i++;
        }
       
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        return head;
    }
};