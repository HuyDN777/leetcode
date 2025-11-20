class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort (intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        int firstMax = -1, secondMax = -1, ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] > firstMax) {
                ans += 2;
                firstMax = intervals[i][1];
                secondMax = intervals[i][1] - 1;
            }
            else if (intervals[i][0] > secondMax && intervals[i][0] <= firstMax) {
                ans += 1; 
                secondMax = firstMax;
                firstMax = intervals[i][1];
            }
        }
        return ans;
    }
};