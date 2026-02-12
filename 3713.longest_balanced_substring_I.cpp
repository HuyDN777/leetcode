class Solution {
    public:
        int longestBalanced(string s) {
            int n = s.length();
            int maxLen = 0;
            for (int i = 0; i < n; ++i) {
                vector<int> freq(26, 0); 
                int distinctCount = 0;
                int maxFreq = 0;
                for (int j = i; j < n; ++j) {
                    int charIdx = s[j] - 'a';
                    if (freq[charIdx] == 0) distinctCount++;
                    freq[charIdx]++;
                    maxFreq = max(maxFreq, freq[charIdx]);
                    int currentLen = j - i + 1;
                    if (maxFreq * distinctCount == currentLen) maxLen = max(maxLen, currentLen);
                }
            }
            
            return maxLen;
        }
    };