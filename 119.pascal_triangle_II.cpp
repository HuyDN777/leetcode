class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal;
        if(rowIndex >= 0) pascal.push_back({1});
        if(rowIndex >= 1) pascal.push_back({1, 1});
        for(int i = 2; i <= rowIndex; i++) {
            vector<int> row(i + 1, 1);
            for(int j = 1; j < i; j++) row[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            pascal.push_back(row);
        }
        return pascal[rowIndex];
    }
};