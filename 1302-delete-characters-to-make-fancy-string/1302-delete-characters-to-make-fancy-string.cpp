class Solution {
public:
    string makeFancyString(string s) {
        string result;
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            // Check if the last two characters in result are the same as the current character
            if (result.size() >= 2 &&
                result[result.size() - 1] == s[i] &&
                result[result.size() - 2] == s[i]) {
                continue;  // Skip this character to avoid three consecutive characters
            }
            // Otherwise, add the character to result
            result += s[i];
        }
        
        return result;  // Return the result as the final fancy string
    }
};