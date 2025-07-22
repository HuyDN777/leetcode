class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            return a[1] < b[1]; 
        });

        vector<int> endTimes(n);
        for(int i = 0; i < n; ++i) endTimes[i] = events[i][1];
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for(int i = 0; i < n; ++i) {
            int start = events[i][0];
            int end = events[i][1];
            int val = events[i][2];
            int j = upper_bound(endTimes.begin(), endTimes.end(), start - 1) - endTimes.begin() - 1;

            for(int kk = 1; kk <= k; ++kk) {
                if(i > 0)
                    dp[i][kk] = dp[i - 1][kk];
                else
                    dp[i][kk] = 0;

                int include = val + (j >= 0 ? dp[j][kk - 1] : 0);
                dp[i][kk] = max(dp[i][kk], include);
            }
        }

        return dp[n - 1][k];
    }
};