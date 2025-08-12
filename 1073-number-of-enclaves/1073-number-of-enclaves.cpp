class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>&arr){
        vis[r][c] = 1;
        int n = arr.size();
        int m = arr[0].size();

        if(r-1 >= 0 && vis[r-1][c] == 0 && arr[r-1][c] == 1) dfs(r-1, c, vis, arr);
        if(r+1 < n && vis[r+1][c] == 0 && arr[r+1][c] == 1) dfs(r+1, c, vis, arr);
        if(c-1 >= 0 && vis[r][c-1] == 0 && arr[r][c-1] == 1) dfs(r, c-1, vis, arr);
        if(c+1 < m && vis[r][c+1] == 0 && arr[r][c+1] == 1) dfs(r, c+1, vis, arr);
    }

    int numEnclaves(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m , 0));

        // Left & Right borders
        for(int i = 0; i<n; i++){
            if(!vis[i][0] && arr[i][0] == 1) dfs(i, 0, vis, arr);
            if(!vis[i][m-1] && arr[i][m-1] == 1) dfs(i, m-1, vis, arr);
        }

        // Top & Bottom borders
        for(int i = 0; i<m; i++){
            if(!vis[0][i] && arr[0][i] == 1) dfs(0, i, vis, arr);
            if(!vis[n-1][i] && arr[n-1][i] == 1) dfs(n-1, i, vis, arr);
        }

        // Fill unvisited cells
        int cnt = 0;
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(vis[i][j] == 0 && arr[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};