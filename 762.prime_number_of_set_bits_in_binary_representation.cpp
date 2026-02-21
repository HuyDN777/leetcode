class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        bool isPrime[21] = {false, false, true, true, false, true, false, 
                            true, false, false, false, true, false, true, 
                            false, false, false, true, false, true, false};
        for (int i = left; i <= right; ++i) {
            int setBits = __builtin_popcount(i);
            if (isPrime[setBits]) count++;
        }
        return count;
    }
};