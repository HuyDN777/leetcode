class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int, string>> validCoupons;
        int n = code.size();
        
        for (int i = 0; i < n; ++i) {
            if (!isActive[i]) continue;
            if (code[i].empty()) continue;
            
            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;
            
            int priority = -1;
            if (businessLine[i] == "electronics") priority = 0;
            else if (businessLine[i] == "grocery") priority = 1;
            else if (businessLine[i] == "pharmacy") priority = 2;
            else if (businessLine[i] == "restaurant") priority = 3;
            
            if (priority != -1) validCoupons.push_back({priority, code[i]});
        }
        
        sort(validCoupons.begin(), validCoupons.end());
        
        vector<string> result;
        for (const auto& p : validCoupons) {
            result.push_back(p.second);
        }
        
        return result;
    }
};