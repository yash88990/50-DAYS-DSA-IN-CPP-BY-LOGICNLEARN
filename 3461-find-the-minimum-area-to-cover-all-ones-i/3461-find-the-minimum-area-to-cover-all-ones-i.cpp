class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int top = INT_MAX , down = INT_MIN , left  = INT_MAX , right = INT_MIN;
        for(int i  = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    top = min(top , i);
                    left = min(left , j);
                    right = max(right , j); 
                    down = max(down , i);
                }
            }

        }
        int l = abs(right - left) + 1 ;
        int b = abs(top - down) +  1;
        int area = l *b;
        return area;
        
    }
};