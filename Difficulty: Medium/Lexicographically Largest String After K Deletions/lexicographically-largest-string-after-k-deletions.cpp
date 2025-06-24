class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n=s.size();

stack<char>st;

    
    string ans="";
    
    int i=0;
    while(i<n){
     st.push(s[i]);
         
while(!ans.empty() && ans.back()<st.top() && k>0){
            
            ans.pop_back();
            k--;
        }
       
          ans=ans+st.top();
        
        
        i++;
  
    }
    
    while( k>0){
        
        ans.pop_back();
        
        
        k--;
    }
    
    return ans;
    }
};
