class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& g, vector<vector<int>>& vis) {
        int n = g.size();
        int m = g[0].size();

        vis[i][j] = 1;

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto &dir : dirs) {
            int nx = i + dir[0];
            int ny = j + dir[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || g[nx][ny] == '0') continue;
            dfs(nx, ny, g, vis);
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();

        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && g[i][j] == '1') {
                    dfs(i, j, g, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
