class Solution {
public:
    int numSub(string s) {
        long long MOD = 1e9 + 7, totalCount = 0, currentLength = 0;
        for (char c : s) {
            if (c == '1') currentLength++;
            else {
                if (currentLength > 0) {
                    long long substrings = (currentLength + 1) * currentLength / 2;
                    totalCount = (totalCount + substrings) % MOD;
                }
                currentLength = 0;
            }
        }
        if (currentLength > 0) {
            long long substrings = currentLength * (currentLength + 1) / 2;
            totalCount = (totalCount + substrings) % MOD;
        }
        return (int) totalCount;
    }
};