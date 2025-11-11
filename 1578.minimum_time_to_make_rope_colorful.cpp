class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int totalTime = 0;
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                totalTime += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }

        return totalTime;
    }
};