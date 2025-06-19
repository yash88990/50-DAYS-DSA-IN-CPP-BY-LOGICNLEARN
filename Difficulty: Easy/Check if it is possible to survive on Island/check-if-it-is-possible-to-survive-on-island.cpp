// User function Template for C++

class Solution {
  public:
    int minimumDays(int s,int n, int m) {
        if(m > n)return -1;
        if(s >= 7 && 7 * m > 6 * n)return -1;
        int sunday = s/7;
        int buyingDays = s - sunday;
        int needFood = s * m;
        int ans = 0;
        if(needFood > buyingDays * n)return -1;
        if(needFood % n == 0)ans = needFood / n;
        else ans = needFood / n + 1 ;
        if(ans <= buyingDays)return ans;
        else return -1;
    }
};
