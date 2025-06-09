class Solution {
  public:
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> count;
        queue<char> q;

        for (char ch : s) {
            count[ch]++;
            q.push(ch);

            while (!q.empty() && count[q.front()] > 1) {
                q.pop();
            }
        }

        return q.empty() ? '$' : q.front();
    }
};
