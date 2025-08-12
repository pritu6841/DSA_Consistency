class Solution {
public:
    
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int row, int col) {
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    int rowArr[] = {-1, 0, 1, 0};
    int colArr[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto pr = q.front();
        q.pop();
        int r = pr.first;
        int c = pr.second;

        for (int k = 0; k < 4; k++) {
            int new_r = r + rowArr[k];
            int new_c = c + colArr[k];

            if (new_r >= 0 && new_r < grid.size() &&
                new_c >= 0 && new_c < grid[0].size() &&
                grid[new_r][new_c] == '1' &&
                vis[new_r][new_c] == 0) 
            {
                vis[new_r][new_c] = 1;
                q.push({new_r, new_c});
            }
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