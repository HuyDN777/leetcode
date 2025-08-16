class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, a = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) a++;
            else {
                ans = max(ans, a);
                a = 1;
            }
        }
        ans = max(ans,a);
        return ans;
    }
};