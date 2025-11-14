class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < queries.size(); i++) {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            for (int j = r1; j <= r2; j++) {
                result[j][c1] += 1; 
                if (c2 + 1 < n) { 
                    result[j][c2 + 1] -= 1;
                }
            }
        } 
        for (int r = 0; r < n; r++) {
            for (int c = 1; c < n; c++) { 
                result[r][c] += result[r][c - 1];
            }
        }

        return result;      
    }
};