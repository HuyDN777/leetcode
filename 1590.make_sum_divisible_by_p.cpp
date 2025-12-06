class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum % p;
        if (target == 0) return 0; 
        unordered_map<int, int> lastSeen;
        lastSeen[0] = -1;

        long long currentSum = 0;
        int minLen = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int currentMod = currentSum % p;
            int needed = (currentMod - target + p) % p;

            if (lastSeen.count(needed)) minLen = min(minLen, i - lastSeen[needed]);
            lastSeen[currentMod] = i;
        }
        return minLen == nums.size() ? -1 : minLen;
    }
};