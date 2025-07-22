class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));
        int res = 1;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                int mod1 = (nums[j] + nums[i]) % k;
                for(int m = 0; m < k; ++m) {
                    if(mod1 == m) {
                        dp[i][m] = max(dp[i][m], dp[j][m] + 1);
                        res = max(res, dp[i][m]);
                    }
                }
            }
        }
        return res;
    }
};