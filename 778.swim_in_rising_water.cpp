class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        pq.push({grid[0][0], 0, 0});
        vector<int> dir = {0, 1, 0, -1, 0};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int t = cur[0], x = cur[1], y = cur[2];
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            if (x == n-1 && y == n-1) return t;

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k], ny = y + dir[k+1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
                pq.push({max(t, grid[nx][ny]), nx, ny});
            }
        }
        return -1;
    }
};
