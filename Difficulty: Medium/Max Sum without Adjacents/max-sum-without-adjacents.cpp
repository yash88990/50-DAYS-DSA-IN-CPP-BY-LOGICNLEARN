// User function template for C++
class Solution {
public:
    int findMaxSum(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        if (arr.size() == 1) {
            return arr[0];
        }

        int include = arr[0];
        int exclude = 0;

        for (int i = 1; i < arr.size(); ++i) {
            int new_include = exclude + arr[i];
            int new_exclude = max(include, exclude);
            
            include = new_include;
            exclude = new_exclude;
        }

        return max(include, exclude);
    }
};