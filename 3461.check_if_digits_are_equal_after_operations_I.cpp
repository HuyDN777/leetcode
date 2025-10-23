class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() != 2) {
            string tmp = "";
            for (int i = 0; i < s.length() - 1; i++) {
                tmp += to_string((s[i] - '0' + s[i + 1] - '0') % 10);
            }
            s = tmp;
        }   
        if (s[0] == s[1]) return true;
        return false;
    }
};