class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        
        for (string &w : words) {
            if (!result.empty()) {
                string last = result.back();
                string s1 = last, s2 = w;
                sort(s1.begin(), s1.end());
                sort(s2.begin(), s2.end());
                if (s1 == s2) continue;
            }
            result.push_back(w);
        }
        return result;
    }
};
