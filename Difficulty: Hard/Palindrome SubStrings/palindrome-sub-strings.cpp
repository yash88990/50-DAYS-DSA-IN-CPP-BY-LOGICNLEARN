

class Solution {
  public:
  
int countPS(string &s) {
    int n = s.size(), count = 0;
    
    // Function to expand around center and count palindromic substrings
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 >= 2) count++; // Only consider length >= 2
            l--;
            r++;
        }
    };
    
    // Check for all possible centers
    for (int i = 0; i < n; i++) {
        expand(i, i);   // Odd length palindromes
        expand(i, i+1); // Even length palindromes
    }
    
    return count;
}


};

