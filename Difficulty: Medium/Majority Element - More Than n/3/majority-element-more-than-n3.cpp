



class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        if (n == 0) return result;

        // Step 1: Candidate selection
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        for (int num : arr) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verification
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        // Step 3: Sort the result
        sort(result.begin(), result.end());
        return result;
    }
};



