class Solution {
public:
    int minOperations(string s) {
        int diff1 = 0, diff2 = 0;
        for (int i = 0; i < s.length(); i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';
            if (s[i] != expected1) diff1++;
            if (s[i] != expected2) diff2++;
        }
        return min(diff1, diff2);
    }
};