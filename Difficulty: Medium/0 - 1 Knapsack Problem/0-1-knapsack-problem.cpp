class Solution {
  public:
  
    int solve(int W, vector<int> &val, vector<int> &wt , int index , vector<vector<int>>&dp){
        //base case
        if(index == 0){
            if(wt[index] <= W)return val[index];
            else return 0;
        }
        if(dp[index][W] != -1)return dp[index][W];
        int include = 0;
        if(wt[index] <= W){
            include = val[index] + solve(W - wt[index] , val , wt , index - 1 , dp);
        }
        int exclude = 0 + solve(W , val , wt , index - 1 , dp);
        dp[index][W] =  max(include , exclude);
        return dp[index][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size() ;
        vector<vector<int>>dp(n , vector<int>(W + 1 , -1));
        return solve(W , val , wt , n - 1 , dp);
        
    }
};