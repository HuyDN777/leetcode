class Solution {
public:
    vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        vector<int> result; 
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (!result.empty() && nums[i] < result.back() && (result.size() + (n - i) > k)) {
                result.pop_back();
            }
            if (result.size() < k) result.push_back(nums[i]);
        }

        return result; 
    }
};