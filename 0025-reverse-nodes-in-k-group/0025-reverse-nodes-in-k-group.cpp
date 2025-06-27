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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0 ;i < k ; i++){
            if(!temp)return head;
            temp = temp->next;
        }
        //reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        int count = 0;
        while(count < k && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;

        }
        //left will be solve by reccursion 
        head->next = reverseKGroup(curr , k);
        return prev;

    }
};