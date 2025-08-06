class Solution {
  public:
    void solve(vector<vector<int>>& adj, vector<int>& vis, vector<int>&dfs, int &node){
        dfs.push_back(node);
        vis[node] = 1;
        for(auto &ele : adj[node]){
            if(vis[ele] == 0)
            solve(adj, vis, dfs, ele);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>vis(n, 0);
        vis[0] = 1;
        vector<int>dfs;
        int node = 0;
        solve(adj, vis, dfs, node);
        return dfs;
    }
};