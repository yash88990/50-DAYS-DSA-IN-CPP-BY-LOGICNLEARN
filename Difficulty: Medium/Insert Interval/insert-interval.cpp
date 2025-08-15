// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, 
                                       vector<int> &newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // Step 1: Add intervals that end before the new interval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval); // Add the merged interval

        // Step 3: Add intervals that start after the new interval ends
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};


