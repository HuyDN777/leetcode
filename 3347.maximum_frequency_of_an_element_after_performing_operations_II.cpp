class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<long long> Ls(n), Rs(n);
        for (int i = 0; i < n; ++i) {
            Ls[i] = (long long)nums[i] - k;
            Rs[i] = (long long)nums[i] + k;
        }
        sort(Ls.begin(), Ls.end());
        sort(Rs.begin(), Rs.end());
        vector<pair<long long,int>> events; events.reserve(2*n);
        for (int i = 0; i < n; ++i) {
            events.emplace_back(Ls[i], 1);
            events.emplace_back(Rs[i] + 1, -1); 
        }
        sort(events.begin(), events.end());
        int cur = 0;
        int cntRange_max = 0;
        for (auto &ev : events) {
            cur += ev.second;
            cntRange_max = max(cntRange_max, cur);
        }

        int ans = 0;
        ans = max(ans, min(cntRange_max, numOperations));

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && nums[j] == nums[i]) ++j;
            int cntEq = j - i;
            long long v = nums[i];
            long long L = v - k, R = v + k;
            int cntL = int(upper_bound(Ls.begin(), Ls.end(), v) - Ls.begin());      
            int cntRless = int(upper_bound(Rs.begin(), Rs.end(), v - 1) - Rs.begin()); 
            int cntRange = cntL - cntRless;

            int convertible = cntRange - cntEq;
            int freq = cntEq + min(numOperations, convertible);
            ans = max(ans, freq);

            i = j;
        }

        return ans;
    }
};