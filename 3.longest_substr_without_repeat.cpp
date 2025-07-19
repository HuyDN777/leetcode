class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), map[128] = {0}, start = 0, max = 0, count = 0;
        for(int i = 0; i < len; i++) {
            if(map[s[i]]==0) {
                map[s[i]] = 1;
                count++;
            } 
            else {
                while(map[s[i]] != 0) {
                    map[s[start]] = 0;
                    start++;
                    count--;
                }
                map[s[i]] = 1;
                count++;
            }
            if(count >= max) max = count; 
        }
        return max;
    }
};