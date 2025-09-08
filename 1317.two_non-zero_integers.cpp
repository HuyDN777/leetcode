class Solution {
public:
    bool check(int a) {
        while (a != 0) {
            int r = a % 10;
            if (r == 0) return false;
            a /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (check(i) && check(n - i)) {
                ans.push_back(i);
                ans.push_back(n - i);
                break;
            }
        }
        return ans;
    }
};