class Solution {
public:
    int possibleStringCount(string word) {
         int frequency = 1; 
      
        // Loop through the string starting from the second character
        for (int i = 1; i < word.size(); ++i) {
            // Increment the frequency counter if the current character matches the previous one
            frequency += (word[i] == word[i - 1]);
        }
      
        // Return the final frequency count
        return frequency;
    }
};