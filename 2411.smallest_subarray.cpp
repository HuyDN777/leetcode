class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        vector<int> bitPos(32, -1);

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) bitPos[b] = i;
            }

            int farthest = i;
            for (int b = 0; b < 32; ++b) {
                if (bitPos[b] != -1) {
                    farthest = max(farthest, bitPos[b]);
                }
            }

            res[i] = farthest - i + 1;
        }

        return res;
    }
};
