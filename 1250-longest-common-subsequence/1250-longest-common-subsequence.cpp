class Solution {
public:
    int solve(string & a , string & b, int i ,int j, vector<vector<int>> &dp  ){
        //base case
        if( i == a.size() || j == b.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        if(a[i] == b[j])ans = 1 + solve(a , b , i+1 , j+1 , dp);
        else ans = max(solve(a , b , i+1 , j, dp) , solve(a , b, i, j+1 , dp));
        return dp[i][j] = ans;

    }
    int solvetabulation(string a , string b){
        vector<vector<int>>dp(a.length() +1  , vector<int>(b.length() + 1 , 0));
        for(int i = a.length() - 1 ; i >= 0 ; i--){
            for(int j = b.length() -1 ; j >= 0 ; j--){
                int ans = 0;
                if(a[i] == b[j])ans = 1 + dp[i+1][j+1];
                else ans = max(dp[i+1][j] , dp[i][j+1]);
                dp[i][j] = ans;
            }
            
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>dp(text1.size() , vector<int>(text2.size() , -1));
        // return solve(text1 , text2, 0,0 , dp);
        return solvetabulation(text1, text2);
    }
};