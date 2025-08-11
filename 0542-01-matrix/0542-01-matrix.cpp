class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n1 = mat.size();
        int m = mat[0].size();
        queue<pair<int, pair<int, int>>>q;
        vector<vector<int>>vis(n1, vector<int>(m, 0));
        vector<vector<int>>ans(n1 , vector<int>(m, 0));

        for(int i = 0; i<n1; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, {j, 0}});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            auto a = q.front();
            int r = a.first;
            int c = a.second.first;
            int n = a.second.second;
            q.pop();
            
            ans[r][c] = n;
            if(r-1 >= 0 && vis[r-1][c] == 0){
                q.push({r-1, {c, n+1}});
                vis[r-1][c] = 1;
            }
            if(r+1 < n1 && vis[r+1][c] == 0){
                q.push({r+1, {c, n+1}});
                vis[r+1][c] = 1;
            }
            if(c-1 >= 0 && vis[r][c-1] == 0){
                q.push({r, {c-1, n+1}});
                vis[r][c-1] = 1;
            }
            if(c+1 < m && vis[r][c+1] == 0){
                q.push({r, {c+1, n+1}});
                vis[r][c+1] = 1;
            }
        }
        return ans;
    }
};