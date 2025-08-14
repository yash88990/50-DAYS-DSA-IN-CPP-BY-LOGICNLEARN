class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0 , e = nums.size()-1 , index = -1;
        while(s <= e){
            int m = s + ( e - s )/2;
            if(nums[m] <= target){
                index = m;
                s = m+1;
            }else 
               e = m - 1;
        }
        if(index != -1 && nums[index] == target)return index;
        else return index + 1;
    }
};