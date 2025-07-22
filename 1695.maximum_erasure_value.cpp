class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> subarray;
        int left = 0, right = 0, maxSum = 0, currentSum = 0;
        while(right < nums.size()) {
            if(subarray.count(nums[right]) == 0) {
                currentSum += nums[right];
                subarray.insert(nums[right]);
                maxSum = max(maxSum, currentSum);
                right++;
            } else {
                subarray.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
        }
        return maxSum;
    }
};
