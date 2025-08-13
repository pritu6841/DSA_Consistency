class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vis[r][c] = 1;

        // 4-direction movement
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && arr[nr][nc] == 'O') {
                dfs(nr, nc, vis, arr);
            }
        }
    }
    void solve(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m , 0));

        // Left & Right borders
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && arr[i][0] == 'O') dfs(i, 0, vis, arr);
            if(!vis[i][m-1] && arr[i][m-1] == 'O') dfs(i, m-1, vis, arr);
        }

        // Top & Bottom borders
        for(int i = 0; i<m; i++){
            if(!vis[0][i] && arr[0][i] == 'O') dfs(0, i, vis, arr);
            if(!vis[n-1][i] && arr[n-1][i] == 'O') dfs(n-1, i, vis, arr);
        }

        // Fill unvisited cells
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0) arr[i][j] = 'X';
            }
        }
    }
};
