class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        vis[node] = 1;
        for(int ele = 0; ele < adj[node].size(); ele++) {
            if(vis[ele] == 0 && adj[node][ele] == 1) {
                dfs(adj, vis, ele);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for(int node = 0; node < n; node++) {
            if(vis[node] == 0) {
                dfs(isConnected, vis, node);
                cnt += 1;
            }
        }

        return cnt;
    }
};
