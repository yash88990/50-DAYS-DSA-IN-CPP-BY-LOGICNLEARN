// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int>temparray;
        for(int i = 0 ; i < N ; i++ ){
            for(int j = 0 ; j < N ; j++){
                temparray.push_back(Mat[i][j]);
            }
        }
        sort(temparray.begin() , temparray.end());
        int index = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                Mat[i][j] = temparray[index++];
            }
        }
        return  Mat;
        
    }
};