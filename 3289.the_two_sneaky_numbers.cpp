class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        vector<int> counts(n, 0);
        
        vector<int> result;

        for (int num : nums) {
            counts[num]++;
            
            if (counts[num] == 2) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};