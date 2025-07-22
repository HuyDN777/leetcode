class Solution {
public:
    void Try(int i, int n, string s, vector<string>& result) {
        if(s.length() == n) {
            result.push_back(s);
            return;
        }

        if(s.empty() || s.back() == '1') {
            Try(i + 1, n, s + '0', result);
            Try(i + 1, n, s + '1', result);
        } else Try(i + 1, n, s + '1', result);
    }

    vector<string> validStrings(int n) {
        vector<string> result;
        Try(0, n, "", result);
        return result;
    }
};