class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool ok = true;
            for (char c : word) {
                if (broken.count(c)) {
                    ok = false;
                    break;
                }
            }
            if (ok) count++;
        }
        return count;
    }
};