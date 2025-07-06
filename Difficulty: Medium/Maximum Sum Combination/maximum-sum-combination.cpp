class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // Sort both arrays in descending order to get largest elements first
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        // Max-heap to store {sum, {index_in_a, index_in_b}}
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // Set to keep track of visited index pairs to avoid duplicates
        set<pair<int, int>> visited;
        
        // Result vector to store top k sums
        vector<int> result;
        
        // Start with the maximum possible sum: a[0] + b[0]
        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});
        
        // Get k maximum sum combinations
        for (int count = 0; count < k && !pq.empty(); count++) {
            // Get the current maximum sum combination
            auto current = pq.top();
            pq.pop();
            
            int sum = current.first;
            int i = current.second.first;   // index in array a
            int j = current.second.second;  // index in array b
            
            // Add this sum to our result
            result.push_back(sum);
            
            // Add next possible combinations to heap if they're valid and not visited
            
            // Try next element from array a with same element from array b
            if (i + 1 < a.size() && visited.find({i + 1, j}) == visited.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            
            // Try same element from array a with next element from array b
            if (j + 1 < b.size() && visited.find({i, j + 1}) == visited.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        
        return result;
    }
};