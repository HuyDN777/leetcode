class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0;
        unordered_map<long long, long long> sum;
        sum.reserve(power.size()*2);
        for (int x : power) {
            sum[x] += (long long)x;
        }
        vector<long long> vals;
        vals.reserve(sum.size());
        for (auto &p : sum) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        int m = (int)vals.size();
        vector<long long> dp(m, 0);

        for (int i = 0; i < m; ++i) {
            long long curVal = vals[i];
            long long take = sum[curVal];
            long long target = curVal - 3;
            int j = (int)(upper_bound(vals.begin(), vals.begin() + i, target) - vals.begin()) - 1;

            if (j >= 0) take += dp[j];

            long long skip = (i > 0 ? dp[i-1] : 0);
            dp[i] = max(skip, take);
        }

        return dp.empty() ? 0 : dp.back();
    }
};