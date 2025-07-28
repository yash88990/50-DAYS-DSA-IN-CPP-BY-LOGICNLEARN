class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
         int n = mat.size();
        
        int maxi =0,sum =0;
        
        for(int i=0;i<n;i++){
            int x=0,y=0;
            for(int j=0;j<n;j++){
                x+= mat[i][j];
                y+=mat[j][i];
                sum+= mat[i][j];
            }
            maxi = max({x,y,maxi});
        }
        
        return n*maxi-sum;
    }
};