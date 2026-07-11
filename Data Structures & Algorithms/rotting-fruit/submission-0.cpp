class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        int dirs[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 2) q.push({0, {i, j}});
            }
        }

        int res = 0;

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            int t = front.first;
            int x = front.second.first;
            int y = front.second.second;

            for (auto &dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (g[nx][ny] == 1) {
                    g[nx][ny] = 2;
                    q.push({t + 1, {nx, ny}});
                    res = max(res, t + 1);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) return -1;
            }
        }

        return res;
    }
};