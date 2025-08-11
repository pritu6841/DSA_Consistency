class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        for (auto &e : edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(V, 0);

        for (int start = 0; start < V; start++) {
            if (!vis[start]) {
                queue<pair<int, int>> q;
                q.push({start, -1});
                vis[start] = 1;

                while (!q.empty()) {
                    auto [node, parent] = q.front();
                    q.pop();

                    for (auto i : mp[node]) {
                        if (vis[i] && i != parent) return true;
                        if (!vis[i]) {
                            vis[i] = 1;
                            q.push({i, node});
                        }
                    }
                }
            }
        }
        return false;
    }
};
