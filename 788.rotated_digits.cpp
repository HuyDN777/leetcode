class Solution {
public:
    bool goodNumber(int x) {
        bool hasChanged = false;
        while (x > 0) {
            int d = x % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) hasChanged = true;
            x /= 10;
        }
        return hasChanged;
    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (goodNumber(i)) ++cnt;
        return cnt;
    }
};
