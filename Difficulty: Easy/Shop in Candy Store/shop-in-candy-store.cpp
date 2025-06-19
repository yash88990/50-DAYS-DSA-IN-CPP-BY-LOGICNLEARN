class Solution {
  public:
    vector<int> candyStore(int c[], int N, int k) {
        // Write Your Code here
        sort(c, c + N);
        int mini = 0;
        int buy = 0 ;
        int free = N-1;
        while(buy <= free){
            mini += c[buy];
            buy++;
            free -= k;
        }
        int maxi  =0;
        buy = N-1;
        free = 0;
        while(free <= buy){
            maxi += c[buy];
            buy--;
            free += k;
        }
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};