class Solution {
public:
    bool issafe(int row , int col , vector<vector<string>>& board, int n){
        int x = row, y = col;
        while(y >= 0){
            if(board[x][y] == "Q") return false;
            y--;
        }
        x = row, y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == "Q") return false;
            x--; y--;
        }
        x = row, y = col;
        while(x < n && y >= 0){
            if(board[x][y] == "Q") return false;
            x++; y--;
        }
        return true;
    }

    void addsolution(vector<vector<string>> &board, vector<vector<string>> &ans, int n){
        vector<string> temp;
        for(int i = 0; i < n; i++){
            string row = "";
            for(int j = 0; j < n; j++){
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    void solve(int col , vector<vector<string>> &ans, vector<vector<string>>& board , int n){
        if(col == n){
            addsolution(board, ans, n);
            return;
        }
        for(int row = 0; row < n; row++){
            if(issafe(row, col, board, n)){
                board[row][col] = "Q";
                solve(col + 1, ans, board, n);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};
