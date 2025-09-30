// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        unordered_set<char> seen;
        string result = "";
        for(char ch : s){
            if(seen.find(ch) == seen.end()){
                result += ch;
                seen.insert(ch);
                
            }
        }
        return result;
    }
};