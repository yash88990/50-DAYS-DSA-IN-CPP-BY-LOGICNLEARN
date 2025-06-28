/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* solve(vector<int>&nums , int start , int end){
        if(start > end)return NULL;
        int mid = start + ( end - start)/2;
        Node* root = new Node(nums[mid]);
        root->left = solve(nums , start , mid - 1);
        root->right = solve(nums , mid+ 1 , end);
        return root;
        
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        return solve(nums , 0 , nums.size() - 1);
        
    }
};