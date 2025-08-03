class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos, prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pos.push_back(fruits[i][0]);
            prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
        }

        int res = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (left <= right) {
                int leftPos = fruits[left][0];
                int rightPos = fruits[right][0];
                int steps = min(abs(startPos - leftPos), abs(startPos - rightPos)) + (rightPos - leftPos);

                if (steps <= k) break;
                left++;
            }
            if (left <= right) {
                int totalFruits = prefixSum[right + 1] - prefixSum[left];
                res = max(res, totalFruits);
            }
        }

        return res;
    }
};
