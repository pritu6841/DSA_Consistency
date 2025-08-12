// User function Template for C++

class Solution {
  public:
  vector<pair<int, int>> bfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int row, int col){
        vis[row][col] = 1;
        vector<pair<int, int>>ans;
        int base_r = row;
        int base_c = col;
        ans.push_back({0, 0});
        queue<pair<int, int>>q;
        q.push(make_pair(row, col));
        while(!q.empty()){
            pair<int, int> pr = q.front();
            q.pop();
            int i = pr.first;
            int j = pr.second;
            if ((i-1 >= 0) && (grid[i-1][j] == 1 && vis[i-1][j] == 0)) {
                vis[i-1][j] = 1;
                ans.push_back({i-1 - base_r, j - base_c});
                q.push({i-1, j});
            }
            if ((j-1 >= 0 && grid[i][j-1] == 1) && vis[i][j-1] == 0) {
                vis[i][j-1] = 1;
                ans.push_back({i - base_r, j-1 - base_c});
                q.push({i, j-1});
            }
            if ((j+1 < grid[0].size() && grid[i][j+1] == 1 && vis[i][j+1] == 0)) {
                vis[i][j+1] = 1;
                ans.push_back({i - base_r, j+1 - base_c});
                q.push({i, j+1});
            }
            if ((i+1 < grid.size()) && (grid[i+1][j] == 1 && vis[i+1][j] == 0)) {
                vis[i+1][j] = 1;
                ans.push_back({i+1 - base_r, j - base_c});
                q.push({i+1, j});
            }
        }
        return ans;
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();int m = grid[0].size();
        set<vector<pair<int, int>>>s;
        int cnt = 0;
        vector<pair<int, int>>temp;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(grid[row][col] == 1 && vis[row][col] == 0) {
                    temp = bfs(grid, vis, row, col);
                    s.insert(temp);
                }
            }
        }
        return s.size();
        
    }
};
