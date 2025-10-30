class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;

        int ans = 0;
        for (int start = 0; start < n; ++start) {
            if (nums[start] != 0) continue; 

            for (int dir0 : {1, -1}) {
                vector<int> a = nums; 
                int pos = start;
                int dir = dir0;
                long long steps = 0;
                long long LIMIT = (total + 1) * (long long)n + 100;

                while (pos >= 0 && pos < n && steps <= LIMIT) {
                    if (a[pos] == 0) {
                        pos += dir;
                    } else {
                        a[pos] -= 1;
                        dir = -dir; 
                        pos += dir;
                    }
                    ++steps;
                }

                if (steps > LIMIT) continue;

                bool ok = true;
                for (int x : a) {
                    if (x != 0) { ok = false; break; }
                }
                if (ok) ++ans;
            }
        }
        return ans;
    }
};