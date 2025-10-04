

// User function template for C++

class Solution {
  public:
   

void findPathsUtil(vector<vector<int>> &mat, int n, int x, int y, vector<string> &result, string path, vector<vector<int>> &visited) {
    // Base cases
    if (x < 0 || y < 0 || x >= n || y >= n || mat[x][y] == 0 || visited[x][y] == 1) {
        return;
    }

    // If destination is reached
    if (x == n-1 && y == n-1) {
        result.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[x][y] = 1;

    // Explore all possible directions
    if (x + 1 < n && !visited[x + 1][y]) { // Down
        findPathsUtil(mat, n, x + 1, y, result, path + "D", visited);
    }
    if (x - 1 >= 0 && !visited[x - 1][y]) { // Up
        findPathsUtil(mat, n, x - 1, y, result, path + "U", visited);
    }
    if (y + 1 < n && !visited[x][y + 1]) { // Right
        findPathsUtil(mat, n, x, y + 1, result, path + "R", visited);
    }
    if (y - 1 >= 0 && !visited[x][y - 1]) { // Left
        findPathsUtil(mat, n, x, y - 1, result, path + "L", visited);
    }

    // Unmark the cell as visited for other paths
    visited[x][y] = 0;
}

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> result;
    int n = maze.size();
    if (maze[0][0] == 0 || maze[n-1][n-1] == 0) {
        return result; // No path exists if start or end is blocked
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    findPathsUtil(maze, n, 0, 0, result, "", visited);
    sort(result.begin(), result.end());
    return result;
    }
};



