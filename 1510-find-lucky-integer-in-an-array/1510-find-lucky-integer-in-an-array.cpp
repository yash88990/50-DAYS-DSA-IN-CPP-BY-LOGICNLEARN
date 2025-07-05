class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int num : arr)freq[num]++;
        int ans = -1;
        for(auto &entry : freq){
            if(entry.first == entry.second){
                ans = max (entry.first, ans);
            }
        }
        return ans;
    }
};