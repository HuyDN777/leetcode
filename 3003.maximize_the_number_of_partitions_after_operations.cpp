class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        const int INF_NEG = -1000000000;
        vector<unordered_map<int,int>> dp0(n+1), dp1(n+1);
        dp0[0][0] = 1; 

        for (int i = 0; i < n; i++) {
            char c = s[i];
            int bit = c - 'a';
            for (auto &pr : dp0[i]) {
                int mask = pr.first;
                int parts = pr.second;
                int newMask = mask | (1 << bit);
                if (__builtin_popcount(newMask) <= k) {
                    dp0[i+1][newMask] = max(dp0[i+1][newMask], parts);
                } else {
                    dp0[i+1][1 << bit] = max(dp0[i+1][1 << bit], parts + 1);
                }
                for (int x = 0; x < 26; x++) {
                    if (x == bit) continue;
                    int altMask = mask | (1 << x);
                    if (__builtin_popcount(altMask) <= k) {
                        dp1[i+1][altMask] = max(dp1[i+1][altMask], parts);
                    } else {
                        dp1[i+1][1 << x] = max(dp1[i+1][1 << x], parts + 1);
                    }
                }
            }

            for (auto &pr : dp1[i]) {
                int mask = pr.first;
                int parts = pr.second;
                int newMask = mask | (1 << bit);
                if (__builtin_popcount(newMask) <= k) {
                    dp1[i+1][newMask] = max(dp1[i+1][newMask], parts);
                } else {
                    dp1[i+1][1 << bit] = max(dp1[i+1][1 << bit], parts + 1);
                }
            }
        }

        int ans = 0;
        for (auto &pr : dp0[n]) ans = max(ans, pr.second);
        for (auto &pr : dp1[n]) ans = max(ans, pr.second);
        return ans;
    }
};