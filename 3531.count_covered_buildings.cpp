class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minRow(n + 1, 1e9);
        vector<int> maxRow(n + 1, -1e9);
        vector<int> minCol(n + 1, 1e9);
        vector<int> maxCol(n + 1, -1e9);

        for (const auto& b : buildings) {
            int r = b[0];
            int c = b[1];
            if (c < minRow[r]) minRow[r] = c;
            if (c > maxRow[r]) maxRow[r] = c;
            if (r < minCol[c]) minCol[c] = r;
            if (r > maxCol[c]) maxCol[c] = r;
        }

        int count = 0;
        for (const auto& b : buildings) {
            int r = b[0];
            int c = b[1];
            if (c > minRow[r] && c < maxRow[r] && r > minCol[c] && r < maxCol[c]) count++;
        }
        
        return count;
    }
};