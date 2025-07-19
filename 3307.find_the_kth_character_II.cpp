class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        __int128_t len = 1;
        for(int i = 0; i < operations.size(); ++i) {
            len *= 2;
        }

        int shift = 0;
        int n = operations.size();

        for(int i = n - 1; i >= 0; --i) {
            len /= 2;
            if(k >= len) {
                k -= len;
                if(operations[i] == 1) shift++;
            }
        }

        return (char)((('a' - 'a') + shift) % 26 + 'a');
    }
};