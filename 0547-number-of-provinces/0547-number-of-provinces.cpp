class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node){
        vis[node] = 1;
        for(int ele = 0 ; ele<isConnected[node].size(); ele++){
            if(vis[ele] == 0 && isConnected[node][ele] == 1) dfs(isConnected, vis, ele);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<int>vis(n, 0);
        for(int node = 0; node < n; node++){
            if(vis[node] == 0){
                dfs(isConnected, vis, node);
                cnt += 1;
            }
        }
        return cnt;
    }
};