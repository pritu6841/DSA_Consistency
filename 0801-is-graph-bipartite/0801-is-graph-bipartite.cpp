class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> clr(n, -1);

        for (int start = 0; start < n; start++) {
            if (clr[start] == -1) { // new component
                clr[start] = 0;
                queue<int> q;
                q.push(start);

                while (!q.empty()) {
                    int curr_node = q.front();
                    q.pop();

                    for (int node : graph[curr_node]) {
                        if (clr[node] == -1) { 
                            clr[node] = 1 - clr[curr_node]; // opposite color
                            q.push(node);
                        }
                        else if (clr[node] == clr[curr_node]) {
                            return false; // same color conflict
                        }
                    }
                }
            }
        }
        return true;
    }
};
