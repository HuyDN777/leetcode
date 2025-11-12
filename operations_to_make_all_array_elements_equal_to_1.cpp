class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums) {
            if (x == 1) {
                ones++;
            }
        }
        if (ones > 0) {
            return n - ones;
        }

        int min_len = n + 1; 

        for (int i = 0; i < n; ++i) {
            int current_gcd = nums[i];
            for (int j = i; j < n; ++j) {
                current_gcd = std::gcd(current_gcd, nums[j]); 
                
                if (current_gcd == 1) {
                    int len = j - i + 1;
                    min_len = std::min(min_len, len);
                    break; 
                }
            }
        }
        if (min_len == n + 1) {
            return -1;
        }
        return (min_len - 1) + (n - 1);
    }
};