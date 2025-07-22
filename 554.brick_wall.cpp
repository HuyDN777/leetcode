class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> gaps;
        for(int i = 0; i < wall.size(); i++) {
            long long pos = 0;
            for(int j = 0; j < wall[i].size() - 1; j++) {
                pos += (long long )wall[i][j];
                gaps[pos]++;
            }
        }
        int maxVal = 0;
        for(auto& [key, value] : gaps) {
            maxVal = max(maxVal, value);
        }
        return (wall.size() - maxVal);
    }
};