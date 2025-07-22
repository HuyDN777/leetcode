class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for(auto& road : roads) {
            int u = road[0], v = road[1];
            degrees[u]++;
            degrees[v]++;
            connected[u][v] = true;
            connected[v][u] = true;
        }
        int maxRank = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int rank = degrees[i] + degrees[j];
                if(connected[i][j]) rank -= 1;
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};