class Solution {
  public:
    bool ispal(string &s,int i ,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    void solve(string &s,int i,vector<string> temp,vector<vector<string>> & ans ){
        if(i>=s.length()) {
          ans.push_back(temp);
          return ;
        }
        // if(dp[])
        
        for(int j=i;j<s.length();j++){
            if(ispal(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,temp,ans);
        return ans;
    }
    
};