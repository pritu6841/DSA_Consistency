class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int>ans;
        vector<int>vis(n, 0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            vis[node] = 1;
            q.pop();
            for(int i = 0; i<adj[node].size(); i++){
                if(vis[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                    vis[adj[node][i]] = 1;
                }
            }
        }
        return ans;
        
    }
};