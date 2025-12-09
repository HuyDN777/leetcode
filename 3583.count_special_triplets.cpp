class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long ans = 0;
        const int MOD = 1e9 + 7;
        unordered_map<int, int> right_count;
        for (int num : nums) {
            right_count[num]++;
        }
        unordered_map<int, int> left_count;
        
        for (int x : nums) {
            right_count[x]--;
            long long target = (long long) x * 2;
            if (left_count.count(target) && right_count.count(target)) {
                long long left = left_count[target];
                long long right = right_count[target];
                ans = (ans + left * right) % MOD;
            }
            left_count[x]++;
        }
        
        return (int)ans;
    }
};