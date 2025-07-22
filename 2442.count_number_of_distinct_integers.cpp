class Solution {
public:
    int reverseNumber(int n) {
        int rev = 0;
        while(n != 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    int countDistinctIntegers(vector<int>& nums) {
        set<int> numsSet;
        for(auto i : nums) {
            numsSet.insert(i);
            numsSet.insert(reverseNumber(i));
        }
        return numsSet.size();
    }
};