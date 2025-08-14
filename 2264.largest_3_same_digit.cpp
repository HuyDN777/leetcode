class Solution {
public:
    bool check(const string& s) {
        return s.size() == 3 && s[0] == s[1] && s[1] == s[2];
    }

    string largestGoodInteger(string num) {
        string result = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            string sub = num.substr(i, 3);
            if (check(sub) && (result.empty() || sub > result)) {
                result = sub;
            }
        }
        return result;
    }
};
