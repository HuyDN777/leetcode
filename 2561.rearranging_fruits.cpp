class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]++;

        for (auto& [val, count] : freq) {
            if (count % 2 != 0) return -1;
        }

        map<int, int> count1, count2;
        for (int x : basket1) count1[x]++;
        for (int x : basket2) count2[x]++;

        vector<int> extra1, extra2;
        for (auto& [val, total] : freq) {
            int need = total / 2;
            int diff1 = count1[val] - need;
            int diff2 = count2[val] - need;
            for (int i = 0; i < diff1; ++i) extra1.push_back(val);
            for (int i = 0; i < diff2; ++i) extra2.push_back(val);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        int minVal = min(*min_element(basket1.begin(), basket1.end()),
                         *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            cost += min((long long)min(extra1[i], extra2[i]), 2LL * minVal);
        }

        return cost;
    }
};
