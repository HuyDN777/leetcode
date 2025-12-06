class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> min_prefix_sum(k, 1e18);
        min_prefix_sum[k - 1] = 0;
        for(int i = 0; i < k; ++i) min_prefix_sum[i] = 1e18;
        min_prefix_sum[0] = 0;

        long long current_sum = 0;
        long long max_sum = -1e18;

        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
        
            int remainder = (i + 1) % k;
            if (min_prefix_sum[remainder] != 1e18) max_sum = max(max_sum, current_sum - min_prefix_sum[remainder]);

            min_prefix_sum[remainder] = min(min_prefix_sum[remainder], current_sum);
        }

        return max_sum == -1e18 ? 0 : max_sum; 
    }
};