class Solution {
    public:
        int minimumCost(vector<int>& nums) {
            int sum = nums[0];
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            
            for (size_t i = 1; i < nums.size(); ++i) {
                if (nums[i] < min1) {
                    min2 = min1;
                    min1 = nums[i];
                } else if (nums[i] < min2) min2 = nums[i];
            }
            
            return sum + min1 + min2;
        }
    };