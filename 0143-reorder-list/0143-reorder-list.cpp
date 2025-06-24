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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return ;
        //step1 :1 find middle 
        ListNode* slow = head , *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //step 2 :- spilt into two half
        ListNode* secondhalf = slow->next;
        slow->next = NULL;
        //step 3 :- reverse second half
        ListNode* prev = NULL;
        while(secondhalf){
            ListNode* temp = secondhalf ->next;
            secondhalf->next = prev;
            prev = secondhalf;
            secondhalf = temp;
        }
        //step 4 :- merge them
        ListNode* firsthalf = head , *secondhalfhead = prev;
        while(secondhalfhead){
            ListNode* temp = secondhalfhead->next;
            secondhalfhead->next = firsthalf->next;
            firsthalf->next = secondhalfhead;

            firsthalf = secondhalfhead->next;
            secondhalfhead = temp;
        }
    }
};