class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, weeks  = n / 7, daysRemain = n % 7;
        if (n <= 7) {
            for (int i = 1; i <= n; i++) ans += i;
        } else {
            for (int i = 1; i <= weeks; i++) {
                for (int j = i; j <= i + 6; j++) ans += j;
            }
            if (daysRemain != 0) {
                for (int i = weeks + 1; i <= daysRemain + weeks; i++) ans += i;
            }
        }
        return ans;
    }
};