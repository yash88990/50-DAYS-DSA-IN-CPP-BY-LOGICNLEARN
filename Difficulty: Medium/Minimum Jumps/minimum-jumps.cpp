
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int jumps = 1 ;
        int maxreach = arr[0];
        int steps = arr[0];
        if(arr[0] == 0)return -1;
        for(int i = 1 ; i < n ; i++){
            if(i == n-1)return jumps;
            maxreach = max ( maxreach , arr[i] + i);
            steps--;
            if(steps == 0){
                jumps++;
                if(i >= maxreach )return -1;
                steps = maxreach - i;
            }
        }
        return -1;
    }
};


