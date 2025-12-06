class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1; 
        vector<int> prefix_dp(n + 1, 0);
        prefix_dp[0] = 1;
        deque<int> maxDeque, minDeque;
        int left = 0;

        for (int i = 0; i < n; ++i) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[i]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(i);
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[i]) {
                minDeque.pop_back();
            }
            minDeque.push_back(i);
            while (nums[maxDeque.front()] - nums[minDeque.front()] > k) {
                left++; 
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }
            
            int current_ways = (prefix_dp[i] - (left > 0 ? prefix_dp[left - 1] : 0) + MOD) % MOD;
            dp[i + 1] = current_ways;
            prefix_dp[i + 1] = (prefix_dp[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};