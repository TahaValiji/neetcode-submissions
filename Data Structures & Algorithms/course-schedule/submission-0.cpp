class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> topo, indegree(n);
        for (auto &e : p) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int u = 0; u < n; u++) if (indegree[u] == 0) q.push(u);

        while (!q.empty()) {
            auto u = q.front(); q.pop();
            topo.push_back(u);

            for (auto &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return (int)topo.size() == n;
    }
};
