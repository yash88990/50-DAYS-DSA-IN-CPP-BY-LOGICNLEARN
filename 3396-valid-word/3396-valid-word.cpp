class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)return false;
        int conso = 0, vowel = 0;
        for(int i = 0 ;i < word.size() ; i++){
            if((word[i] >= 'a' && word[i] <= 'z' ) || 
                (word[i] >= 'A' && word[i] <= 'Z' ) || 
                (word[i] >= '0'  && word[i] <= '9') ){
                
                if((word[i] == 'a' ||word[i] == 'e'  || 
                    word[i] == 'i'  || word[i] == 'o'  || 
                    word[i] == 'u')  ||
                    word[i] == 'A' || word[i] == 'E'  || 
                    word[i] == 'I'  || word[i] == 'O'  || word[i] == 'U'){
                    vowel++;
                }else if(isalpha(word[i]))conso++;

            }else return false;
        }
        if(vowel >= 1 && conso >= 1 )return true;
        else return false;
    }
};