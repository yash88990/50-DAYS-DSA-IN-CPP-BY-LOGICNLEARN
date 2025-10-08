// User function template for C++

class Solution {
    private:
    void solve(vector<int> &arr , int start , int end , vector<int>&ans){
        if(start > end)return ;
        int mid = start + ( end - start) / 2 ;
        if(arr[mid] == mid + 1)ans.push_back(mid + 1);
        solve(arr , start , mid -1 , ans);
        solve(arr , mid + 1 , end , ans);
    }
  public:
    // Function to find elements in the array that are equal to their index.
    vector<int> valueEqualToIndex(vector<int>& arr) {
        // code here
       vector<int>ans;
       int n = arr.size();
       
       solve(arr , 0 , n - 1 , ans);
       sort(ans.begin() , ans.end());
       return ans;
        
    }
};