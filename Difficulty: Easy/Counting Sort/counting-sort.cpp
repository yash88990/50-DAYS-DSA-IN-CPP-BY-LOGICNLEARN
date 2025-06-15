class Solution {
  public:
    // Function to arrange all letters of a string in lexicographical
    // order using Counting Sort.
   string countSort(string arr) {
    // Frequency array for 26 lowercase letters
    int freq[26] = {0};
    
    // Count each character
    for(char ch : arr) {
        freq[ch - 'a']++;
    }
    
    // Reconstruct the sorted string
    string sortedStr = "";
    for(int i = 0; i < 26; i++) {
        sortedStr += string(freq[i], 'a' + i);
    }
    
    return sortedStr;
}

};