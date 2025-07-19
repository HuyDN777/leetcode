class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxAdj = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == nums.size() - 1) maxAdj = max(maxAdj, abs(nums[i] - nums[0]));
            else if(abs(nums[i] - nums[i+1]) > maxAdj) maxAdj = abs(nums[i] - nums[i+1]);
        }  
        return maxAdj;
    }
};