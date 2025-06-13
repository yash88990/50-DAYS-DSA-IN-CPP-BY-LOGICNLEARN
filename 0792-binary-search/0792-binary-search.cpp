class Solution {
public:
    int solve(vector<int>& nums, int s , int e , int target){
        //base case 
        if( s > e)return -1;
        int mid = s + ( e - s )/2;
        if(nums[mid] == target)return mid;
        else if(nums[mid] > target){
            return solve(nums , s , mid -1 ,target);
        }else{
            return solve(nums , mid +1  , e , target);
        }
        

    }
    int search(vector<int>& nums, int target) {
        return solve(nums , 0 , nums.size() - 1 , target);
    }
};