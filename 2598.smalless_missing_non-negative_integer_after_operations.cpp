class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            int r = ((x % value) + value) % value;
            freq[r]++;
        }

        int mex = 0;
        while (true) {
            int r = mex % value;
            if (freq[r] > 0) {
                freq[r]--; 
                mex++;
            } else break; 
        }

        return mex;
    }
};