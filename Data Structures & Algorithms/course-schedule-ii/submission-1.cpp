class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> topo;
        vector<int> indegree(V);
        queue<int> q;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            for (auto node : adj[i]) {
                indegree[node]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (topo.size() == V)
            return topo;
        return {};
    }
};