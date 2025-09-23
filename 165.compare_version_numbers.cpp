class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int a = i < v1.size() ? v1[i] : 0;
            int b = i < v2.size() ? v2[i] : 0;
            if (a < b) return -1;
            if (a > b) return 1;
        }
        return 0;
    }
    
    vector<int> split(string s) {
        vector<int> res;
        string num;
        for (char c : s) {
            if (c == '.') {
                res.push_back(stoi(num));
                num.clear();
            } else {
                num.push_back(c);
            }
        }
        if (!num.empty()) res.push_back(stoi(num));
        return res;
    }
};
