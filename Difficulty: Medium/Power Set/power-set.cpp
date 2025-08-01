class Solution {
  public:
    void solve(string s, vector<string> &ans, int idx, string temp){
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        solve(s,ans,idx+1,temp);
        solve(s,ans,idx+1,temp+s[idx]);
        
        return;
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> ans;
        solve(s,ans,0,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};

