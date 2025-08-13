class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis, int parent){
        vis[node] = 1;
        for(auto & i: adj[node]){
            if(!vis[i]){
            if(dfs(adj, i, vis, node)) return true;
            }
            else if(vis[i] == 1 && i != parent) return true;
                
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(V, 0);
        int parent  = -1;

        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(adj, i, vis, parent)) return true;
            }
        }        
        return false;
    }
};
