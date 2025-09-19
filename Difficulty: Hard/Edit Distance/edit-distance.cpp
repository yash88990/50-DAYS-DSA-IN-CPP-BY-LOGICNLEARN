class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(string& a  , string& b ,int i , int j , vector<vector<int>>&dp){
        //base case 
        if(i == a.length())return b.length() - j;
        if(j == b.length())return a.length() - i;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        if(a[i] == b[j])return solve(a , b , i+1 , j+1 , dp);
        else{
            //insert
            int insert = 1 + solve(a , b , i , j+1 , dp);
            //delete
            int deleted = 1 + solve(a , b, i+1 , j  , dp);
            //replace
            int replace = 1 + solve(a , b , i+1 , j+1 , dp);
            ans = min(insert , min(deleted , replace));
        }
        return dp[i][j] = ans;
        
    }
    int editDistance(string& s1, string& s2) {
        // code here
        vector<vector<int>>dp(s1.length()  + 1 , vector<int>(s2.size() + 1  , -1));
        return solve(s1 , s2 , 0 , 0 , dp);
    }
};