class Solution {
public:
    bool isPalindrome(long long x) {
        if(x < 0) return false;
        long long rev = 0, y = x;
        while(x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if(y == rev) return true;
        return false;
    }
};