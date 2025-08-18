// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
    // Step 1: Sort the citations in descending order
    sort(citations.rbegin(), citations.rend());
    
    // Step 2: Find the H-Index
    int h = 0;
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] >= i + 1) {
            h++;
        } else {
            break;
        }
    }
    
    return h;
}

};
