
class TrieNode{
    public:
    char data;
    int childcount;
    TrieNode* children[26];
    bool isTerminal;
    //constructor
    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i < 26 ;i++){
            children[i] = NULL;
        }
        childcount = 0;
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root  ;
    //constructor
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    //insertion 
    void insertWord(string word){
        insertUtil(root , word);
    }
    void insertUtil(TrieNode* root , string word){
        //base case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            //absent hai 
            child = new TrieNode(word[0]);
            root->childcount++;
            root->children[index] = child;
        }
        //baki ka recc dekh lega 
        insertUtil(child , word.substr(1));
    }
    void lcp(string str , string &ans){
        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            if(root->childcount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }else break;
            if(root->isTerminal)break;
        }
        
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        for(int i = 0 ; i < strs.size() ; i++){
            t->insertWord(strs[i]);
             if(strs.size() == 0 || strs[i] == "")return "";
        }
       
        string first = strs[0];
        string ans = "";
        t->lcp(first , ans);
        return ans;
    }
};