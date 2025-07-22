class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int res = 0;

        for(int x : arr) {
            dp[x] = dp[x - difference] + 1;
            res = max(res, dp[x]);
        }

        return res;
    }
};