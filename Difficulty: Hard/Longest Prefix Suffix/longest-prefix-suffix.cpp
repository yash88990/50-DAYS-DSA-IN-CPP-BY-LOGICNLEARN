class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
          int n = s.length();
    if (n == 0) return 0;

    // Create an array to hold the lengths of the longest prefix suffix values
    std::vector<int> lps_array(n);
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1; // Start from the second character

    while (i < n) {
        if (s[i] == s[length]) {
            length++;
            lps_array[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps_array[length - 1];
            } else {
                lps_array[i] = 0;
                i++;
            }
        }
    }

    // The last value in the lps array will be our answer
    return lps_array[n - 1];

    }
};