class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char,int>hash;
        int n=s.length();
        int left=0,right=0;
        int ans=0;
        while(right<n){
            hash[s[right]]++;
            while((right-left+1)>=k && left<n){
                if(hash.size()==k-1)ans++;
                hash[s[left]]--;
                if(hash[s[left]]==0)hash.erase(s[left]);
                left++;
            }
            right++;
        }
        return ans;
    }
};