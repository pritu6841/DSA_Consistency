class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int, int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int freshOr = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) freshOr++;
            }
        }
        int cnt = -1;
        if(freshOr == 0) return 0;
        q.push({-1, -1});
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            int i = a.first;
            int j = a.second;
            if (i == -1 && j == -1) {
            cnt++;
            if (!q.empty()) { // ✅ Only push if there’s another level
                q.push({-1, -1});
            }
            continue; // Skip neighbor checks
        }
        else{
            if((i-1>=0 ) && grid[i-1][j] == 1){
              q.push({i-1, j});
              grid[i-1][j] = 2;
              freshOr -= 1;
          }
      
          if((i+1<grid.size() ) && grid[i+1][j] == 1){
              q.push({i+1, j});
              grid[i+1][j] = 2;
              freshOr -= 1;
          }
          
          if((j-1>=0 ) && grid[i][j-1] == 1){
              q.push({i, j-1});
              grid[i][j-1] = 2;
              freshOr -= 1;
          }
          
          if((j+1<grid[0].size() ) && grid[i][j+1] == 1){
              q.push({i, j+1});
              grid[i][j+1] = 2;
              freshOr -= 1;
          }
            }
        }
        return (freshOr > 0) ? -1 : cnt;;
    
    }
};