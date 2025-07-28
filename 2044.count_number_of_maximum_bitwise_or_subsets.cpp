class Solution {
public:
    int maxOr = 0;    
    int count = 0; 

    void dfs(vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) count++;
            return;
        }
        dfs(nums, index + 1, currentOr | nums[index]);
        dfs(nums, index + 1, currentOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) {
            maxOr |= num;
        }
        dfs(nums, 0, 0);
        return count;
    }
};
