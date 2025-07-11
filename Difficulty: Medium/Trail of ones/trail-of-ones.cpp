class Solution {
  public:
    int solve(int n, int idx,int prev){
        if(idx==n-1){
            return 1;
        }
        int a =0,b=0;
        if(prev==1){
            a=solve(n,idx+1,0);
        }
        else if(prev==0){
            b=solve(n,idx+1,1)+solve(n,idx+1,0);
        }
        return a+b;
    }
    int countConsec(int n) {
        //the answsr will be total strings - the strings with no 2 consecutive ones appear
        if(n<2)return 0;
        int temp=solve(n,0,0)+solve(n,0,1);
        return (long long)pow(2,n)-temp;
    }
};