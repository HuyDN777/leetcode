class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> powers;
    vector<vector<int>> memo;

    int dfs(int idx, int remain) {
        if (remain == 0) return 1;        
        if (remain < 0 || idx == powers.size()) return 0;
        if (memo[idx][remain] != -1) return memo[idx][remain];

        int res = dfs(idx + 1, remain);

        if (powers[idx] <= remain) {
            res = (res + dfs(idx + 1, remain - powers[idx])) % MOD;
        }

        return memo[idx][remain] = res;
    }

    int numberOfWays(int n, int x) {
        for (int i = 1; ; i++) {
            long long val = 1;
            for (int j = 0; j < x; j++) val *= i;
            if (val > n) break;
            powers.push_back(val);
        }

        memo.assign(powers.size(), vector<int>(n + 1, -1));
        return dfs(0, n);
    }
};
