/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //copy the next node val
        node->val = node->next->val;
        // storeteh nextnode
        ListNode* nextNode = node->next;
        ///point to the next->next
        node->next = nextNode->next;
        delete nextNode;
    }
};