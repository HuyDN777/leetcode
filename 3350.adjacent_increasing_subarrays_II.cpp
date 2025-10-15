class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> lens;
        int len = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) ++len;
            else {
                lens.push_back(len);
                len = 1;
            }
        }
        lens.push_back(len);

        int ans = 0;
        for (int L : lens) {
            ans = max(ans, L / 2);
        }
        for (int i = 0; i + 1 < (int)lens.size(); ++i) {
            ans = max(ans, min(lens[i], lens[i+1]));
        }

        return ans;
    }
};
