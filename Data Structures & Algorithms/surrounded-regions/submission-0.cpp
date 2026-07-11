class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& b, vector<vector<int>>& vis) {
        int n = b.size();
        int m = b[0].size();

        vis[i][j] = 1;

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto &dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || b[x][y] == 'X') continue;
            dfs(x, y, b, vis);
        }
    }
    void solve(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && b[i][0] == 'O') dfs(i, 0, b, vis);
            if (!vis[i][m-1] && b[i][m-1] == 'O') dfs(i, m - 1, b, vis);
        }

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && b[0][j] == 'O') dfs(0, j, b, vis);
            if (!vis[n-1][j] && b[n-1][j] == 'O') dfs(n-1, j, b, vis);
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (!vis[i][j] && b[i][j] == 'O') b[i][j] = 'X';
            }
        }
    }
};
