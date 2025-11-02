class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        const int EMPTY = 0;
        const int GUARD = 1;
        const int WALL = 2;
        const int GUARDED = 3;
        vector<vector<int>> grid(m, vector<int>(n, EMPTY));

        for (auto& g : guards) {
            grid[g[0]][g[1]] = GUARD;
        }
        for (auto& w : walls) {
            grid[w[0]][w[1]] = WALL;
        }

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (auto& g : guards) {
            int r = g[0];
            int c = g[1];
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                while (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int cell = grid[nr][nc];

                    if (cell == GUARD || cell == WALL) {
                        break;
                    }

                    if (cell == EMPTY) {
                        grid[nr][nc] = GUARDED;
                    }

                    nr += dr[i];
                    nc += dc[i];
                }
            }
        }

        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == EMPTY) {
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
};