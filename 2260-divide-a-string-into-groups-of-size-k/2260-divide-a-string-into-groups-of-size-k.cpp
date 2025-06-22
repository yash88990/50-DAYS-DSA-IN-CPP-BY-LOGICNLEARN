class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int stringLength = s.size();
        // If string length is not a multiple of k, append 'fill' characters
        if (stringLength % k) {
            for (int i = 0; i < k - stringLength % k; ++i) {
                s.push_back(fill);
            }
        }
        vector<string> substrings;
        // Divide the string into substrings of length k
        for (int i = 0; i < s.size() / k; ++i) {
            substrings.push_back(s.substr(i * k, k));
        }
        return substrings; // Return the vector of substrings
    }
};