class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                string reversed_word = words[j];
                reverse(reversed_word.begin(), reversed_word.end());
                if (reversed_word == words[i]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};