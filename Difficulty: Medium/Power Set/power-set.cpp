class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        int total = 1 << n; // 2^n subsequences
        vector<string> result;

        for (int i = 1; i < total; i++) {
            string subseq = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subseq += s[j];
                }
            }
            result.push_back(subseq);
        }

        sort(result.begin(), result.end()); // Lexicographical order
        return result;
    }
};
