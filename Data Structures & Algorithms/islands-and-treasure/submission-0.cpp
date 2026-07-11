class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) q.push({i, j});
            }
        }

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            int x = front.first;
            int y = front.second;

            for (auto &dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (g[x][y] + 1 < g[nx][ny]) {
                    g[nx][ny] = g[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
