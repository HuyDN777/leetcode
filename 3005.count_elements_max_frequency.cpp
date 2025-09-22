class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0, maxFreq;
        vector<pair<int, int>> vec;
        map<int, int> mp;
        for (int num : nums) mp[num]++;
        for (auto pair : mp) vec.push_back(pair);
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });
        maxFreq = vec[0].second;
        for (auto pair : vec) {
            if (pair.second == maxFreq) ans += pair.second;
            else break;
        }
        return ans; 
    }
};