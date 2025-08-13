class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis, vector<int>& visPath) {
        vis[node] = 1;
        visPath[node] = 1;

        for (auto &ele : adj[node]) {
            if (vis[ele] == 0) {
                if (dfs(adj, ele, vis, visPath)) return true;
            }
            else if (visPath[ele] == 1) {
                return true;
            }
        }

        visPath[node] = 0; // backtrack
        return false;
    }
    
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<int> visPath(V, 0);
        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(adj, i, vis, visPath)) return false;
            }
        }
        return true;
    }
};