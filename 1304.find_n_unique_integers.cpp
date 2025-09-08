class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        if (n % 2 !=  0) {
            int i = 1;
            for (int j = 1; j <= (n - 1) / 2; j++) {
                ans.push_back(i);
                ans.push_back((-1) * i);
                i++;
            }
            ans.push_back(0);
        }
        else {
            int i = 1;
            for (int j = 1; j <= n / 2; j++) {
                ans.push_back(i);
                ans.push_back((-1) * i);
                i++;
            }
        }
        return ans;
    }
};