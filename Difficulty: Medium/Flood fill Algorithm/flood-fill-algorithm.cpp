class Solution {
  public:
  void bfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int row, int col, int newColor){
        vis[row][col] = 1;
        int oriColor = grid[row][col];
        grid[row][col] = newColor;
        queue<pair<int, int>>q;
        q.push(make_pair(row, col));
        while(!q.empty()){
            pair<int, int> pr = q.front();
            q.pop();
            int i = pr.first;
            int j = pr.second;
            if((i-1 >=0 ) && (grid[i-1][j] == oriColor && vis[i-1][j] == 0)){
                vis[i-1][j] = 1;
                grid[i-1][j] = newColor;
                q.push({i-1, j});
                }
            if((j-1 >= 0 && grid[i][j-1] == oriColor) && vis[i][j-1] == 0){
                vis[i][j-1] = 1;
                grid[i][j-1] = newColor;
                q.push({i, j-1});
                }
            if((j+1 < grid[0].size() && grid[i][j+1] == oriColor && vis[i][j+1] == 0)) {
                vis[i][j+1] = 1;
                grid[i][j+1] = newColor;
                q.push({i, j+1});
                }
            if((i+1 < grid.size()) && (grid[i+1][j] == oriColor && vis[i+1][j] == 0)){
                vis[i+1][j] = 1;
                grid[i+1][j] = newColor;
                q.push({i+1, j});
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size(); int m = image[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        bfs(image, vis, sr, sc, newColor);
        return image;
    }
};