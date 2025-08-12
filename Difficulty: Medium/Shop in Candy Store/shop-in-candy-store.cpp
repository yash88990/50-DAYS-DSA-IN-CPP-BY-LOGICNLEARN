class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin() , prices.end());
        int N = prices.size();
        int mini = 0;
        int buy = 0 ;
        int free = N-1;
        while(buy <= free){
            mini += prices[buy];
            buy++;
            free -= k;
        }
        int maxi  =0;
        buy = N-1;
        free = 0;
        while(free <= buy){
            maxi += prices[buy];
            buy--;
            free += k;
        }
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};