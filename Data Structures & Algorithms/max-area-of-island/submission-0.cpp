class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& g, vector<vector<int>>& vis) {
        int n = g.size();
        int m = g[0].size();

        vis[i][j] = 1;
        int cnt = 1;

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto &dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || !g[x][y]) continue;
            cnt += dfs(x, y, g, vis);
        }

        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        int res = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] || !g[i][j]) continue;
                res = max(res, dfs(i, j, g, vis));
            }
        }

        return res;
    }
};
