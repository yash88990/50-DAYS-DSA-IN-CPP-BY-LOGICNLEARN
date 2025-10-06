class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int>ans;
        int top = 0 , left = 0 ;
        int row = mat.size() ;
        int col = mat[0].size();
        int bottom = row -1 ;
        int right = col - 1;
        
        while(top <= bottom && left <= right){
            //left to righ
            for(int i = left ; i <= right ; i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            
            //top to bottom
            for(int i = top ; i <= bottom ; i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            
            //right to left 
            if(top <= bottom){
                for(int i = right ;i >= left ; i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            //bottom to top
            if(left <= right){
                for(int i = bottom ; i >= top ; i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};