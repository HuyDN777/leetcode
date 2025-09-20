class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> devoweled;

        auto toLower = [](const string &s) {
            string res = s;
            for (auto &c : res) c = tolower(c);
            return res;
        };

        auto devowel = [&](const string &s) {
            string res = toLower(s);
            for (auto &c : res) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '*';
            }
            return res;
        };
        for (auto &w : wordlist) {
            string low = toLower(w);
            if (!caseInsensitive.count(low)) caseInsensitive[low] = w;

            string dv = devowel(w);
            if (!devoweled.count(dv)) devoweled[dv] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string low = toLower(q);
            if (caseInsensitive.count(low)) {
                ans.push_back(caseInsensitive[low]);
                continue;
            }

            string dv = devowel(q);
            if (devoweled.count(dv)) {
                ans.push_back(devoweled[dv]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};