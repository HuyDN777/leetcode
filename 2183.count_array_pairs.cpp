class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        vector<int> divs;
        for (int d = 1; 1LL * d * d <= k; ++d) {
            if (k % d == 0) {
                divs.push_back(d);
                if (d != k / d) divs.push_back(k / d);
            }
        }

        unordered_map<int, long long> cnt;
        long long ans = 0;

        for (int a : nums) {
            int g = gcd(a, k);

            for (int d : divs) {
                if ((1LL * g * d) % k == 0) {
                    ans += cnt[d];
                }
            }

            cnt[g]++;
        }

        return ans;
    }
};