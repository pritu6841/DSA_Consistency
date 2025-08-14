class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int>indegree(V, 0);
        for(int i = 0; i<edges.size(); i++){
            indegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i =0; i<V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int>topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto & i: adj[node]){
                indegree[i]--;
                if(indegree[i] == 0)q.push(i);
            }
        }
    if(topo.size() != V) return false;
    return true;
    }
};