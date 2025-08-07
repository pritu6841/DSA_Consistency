class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int row, int col){
        vis[row][col] = 1;
        queue<pair<int, int>>q;
        q.push(make_pair(row, col));
        while(!q.empty()){
            pair<int, int> pr = q.front();
            q.pop();
            int i = pr.first;
            int j = pr.second;
            if((i-1 >=0 ) && (grid[i-1][j] == '1' && vis[i-1][j] == 0)){
                vis[i-1][j] = 1;
                q.push({i-1, j});
                }
            if((j-1 >= 0 && grid[i][j-1] == '1') && vis[i][j-1] == 0){
                vis[i][j-1] = 1;
                q.push({i, j-1});
                }
            if((j+1 < grid[0].size() && grid[i][j+1] == '1' && vis[i][j+1] == 0)) {
                vis[i][j+1] = 1;
                q.push({i, j+1});
                }
            if((i+1 < grid.size()) && (grid[i+1][j] == '1' && vis[i+1][j] == 0)){
                vis[i+1][j] = 1;
                q.push({i+1, j});
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(grid[row][col] == '1' && vis[row][col] == 0) {
                    bfs(grid, vis, row, col);
                    cnt += 1;
                }
            }
        }
        
        return cnt;
    }
};