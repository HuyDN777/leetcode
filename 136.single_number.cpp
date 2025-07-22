class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(int x : nums) mp[x]++;
        for(const auto& pair : mp) {
            if(pair.second == 1) return pair.first;
        }
        return 0;
    }
};