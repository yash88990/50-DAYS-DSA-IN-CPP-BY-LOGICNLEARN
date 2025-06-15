class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};  // Frequency of characters in current window
        int left = 0;
        int maxFreq = 0;      // Max frequency of any character in the window
        int result = 0;

        for (int right = 0; right < s.size(); ++right) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // If more than k characters need to be replaced
            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
