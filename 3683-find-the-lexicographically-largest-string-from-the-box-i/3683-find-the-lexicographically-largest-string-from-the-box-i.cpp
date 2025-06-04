class Solution {
public:
    string answerString(string word, int numFriends) {
         if (numFriends == 1) {
            return word;
        }

        int n = word.size(); // Get the length of the input word
        string answer; // Initialize an empty string to store the result

        // Iterate over each character in the word
        for (int i = 0; i < n; ++i) {
            // Determine the maximum length of substring we can extract
            int k = std::min(n - i, n - numFriends + 1);

            // Extract the substring from the current position with length k
            string currentSubstring = word.substr(i, k);

            // Update the answer with the maximum lexicographical substring
            answer = std::max(answer, currentSubstring);
        }

        return answer;
    }
};