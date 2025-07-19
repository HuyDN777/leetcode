class Solution {
public:
    int sumDigit(int n) {
        int sum = 0;
        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> groups;
        for (int num : nums) {
            int s = sumDigit(num);
            groups[s].push_back(num);
        }

        int maxSum = -1;

        for (auto& [key, v] : groups) {
            if (v.size() < 2) continue;
            sort(v.begin(), v.end(), greater<int>());
            maxSum = max(maxSum, v[0] + v[1]);
        }

        return maxSum;
    }
};
