class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> withIndex;
        for(int i = 0; i < nums.size(); ++i)
            withIndex.push_back({nums[i], i});
        
        sort(withIndex.begin(), withIndex.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        vector<pair<int, int>> topK(withIndex.begin(), withIndex.begin() + k);

        sort(topK.begin(), topK.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        vector<int> result;
        for(auto& p : topK)
            result.push_back(p.first);
        
        return result;
    }
};