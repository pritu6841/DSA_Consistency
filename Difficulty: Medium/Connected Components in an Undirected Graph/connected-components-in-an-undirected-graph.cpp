class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, int node) {
        vis[node] = 1;
        ans.push_back(node);
        for (int ele : adj[node]) {
            if (!vis[ele]) {
                dfs(adj, vis, ans, ele);
            }
        }
    }

    vector<vector<int>> getComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);  // Adjacency list

        // Build adjacency list from edge list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // because the graph is undirected
        }

        vector<vector<int>> components;
        vector<int> vis(n, 0);

        for (int node = 0; node < n; ++node) {
            if (!vis[node]) {
                vector<int> comp;
                dfs(adj, vis, comp, node);
                components.push_back(comp);
            }
        }

        return components;
    }
};
