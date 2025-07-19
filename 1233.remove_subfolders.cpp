class Solution {
public:
    bool isSubfolder(const string& a, const string& b) {
        return b.size() > a.size() && b.substr(0, a.size()) == a && b[a.size()] == '/';
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;
        for (const string& f : folder) {
            if (res.empty() || !isSubfolder(res.back(), f)) {
                res.push_back(f);
            }
        }

        return res;
    }
};