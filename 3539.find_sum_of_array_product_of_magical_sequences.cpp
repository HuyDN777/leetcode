using int64 = long long;
const int64 MOD = 1000000007;

int64 modpow(int64 a, int64 e){
    int64 r = 1 % MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int64 invmod(int64 x){
    return modpow((x%MOD+MOD)%MOD, MOD-2);
}

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = (int) nums.size();
        if (m == 0) return 0;
        vector<int64> fact(m + 1, 1), invfact(m + 1, 1);
        for (int i = 1; i <= m; i++) fact[i] = fact[i - 1] * i % MOD;
        invfact[m] = invmod(fact[m]);
        for (int i = m; i > 0; i--) invfact[i - 1] = invfact[i] * i % MOD;
        vector<vector<int64>> pow_nums(n, vector<int64>(m + 1, 1));
        for (int i = 0; i < n; i++) {
            int64 base = (nums[i] % MOD + MOD) % MOD;
            for(int c = 1; c <= m; c++) pow_nums[i][c] = pow_nums[i][c - 1] * base % MOD;
        }
        int C = m;
        int K = k;
        vector<vector<vector<int64>>> dp(C + 1, vector<vector<int64>>(m + 1, vector<int64>(K + 1, 0)));
        dp[0][0][0] = 1;

        for (int b = 0; b < n; b++) {
            vector<vector<vector<int64>>> ndp(C + 1, vector<vector<int64>>(m + 1, vector<int64>(K + 1, 0)));

            for (int carry = 0; carry <= C; carry++) {
                for (int used = 0; used <= m; used++) {
                    for (int ones = 0; ones <= K; ones++) {
                        int64 cur = dp[carry][used][ones];
                        if (cur == 0) continue;
                        int maxc = m - used;
                        for (int c = 0; c <= maxc; c++) {
                            int used2 = used + c;
                            int sum = carry + c;
                            int bit = sum & 1; 
                            int carry2 = sum >> 1; 
                            if (carry2 > C) carry2 = C; 
                            int ones2 = ones + bit;
                            if (ones2 > K) continue; 
                            int64 mult = pow_nums[b][c] * invfact[c] % MOD;
                            int64 add = cur * mult % MOD;
                            ndp[carry2][used2][ones2] += add;
                            if (ndp[carry2][used2][ones2] >= MOD) ndp[carry2][used2][ones2] -= MOD;
                        }
                    }
                }
            }
            dp.swap(ndp);
        }
        int64 ans = 0;
        for (int carry = 0; carry <= C; carry++) {
            for (int ones = 0; ones <= K; ones++) {
                int64 sumOverUsed = dp[carry][m][ones];
                if (sumOverUsed == 0) continue;
                int extra = 0;
                int c = carry;
                while (c > 0) {
                    extra += (c & 1);
                    c >>= 1;
                    if (ones + extra > K) break; 
                }
                if (ones + extra != K) continue;

                int64 contrib = sumOverUsed * fact[m] % MOD;
                ans += contrib;
                if (ans >= MOD) ans -= MOD;
            }
        }

        return (int) ans;
    }
};