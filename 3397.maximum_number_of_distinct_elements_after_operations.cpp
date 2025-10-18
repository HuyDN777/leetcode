class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long cur = LLONG_MIN / 2;
        int ans = 0;
        for (long long x : nums) {
            long long left = x - k, right = x + k;
            long long val = max(cur, left);
            if (val <= right) {
                ans++;
                cur = val + 1;
            }
        }
        return ans;
    }
};