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
    int binarytodecomal(vector<int>&nums){
        int ans = 0;
        int n = nums.size();
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            if(nums[i] == 1){
                ans += pow(2, n - 1 - i);
            }
        }
        return ans;
        
    }
    int getDecimalValue(ListNode* head) {
        if(!head)return 1;
        vector<int>ans;
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        int res = binarytodecomal(ans);
        return res;        
    }
};