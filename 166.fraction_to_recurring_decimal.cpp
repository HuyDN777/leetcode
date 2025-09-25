class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";
        
        string ans;
        if ((numerator < 0) ^ (denominator < 0)) ans.push_back('-');
        numerator = abs(numerator);
        denominator = abs(denominator);
        ans += to_string(numerator / denominator);
        long long remainder = numerator % denominator;
        if (remainder == 0) return ans; 
        
        ans.push_back('.');
        unordered_map<long long, int> seen; 
        while (remainder != 0) {
            if (seen.count(remainder)) {
                ans.insert(seen[remainder], "(");
                ans.push_back(')');
                break;
            }
            seen[remainder] = ans.size();
            remainder *= 10;
            ans.push_back('0' + (remainder / denominator));
            remainder %= denominator;
        }
        
        return ans;
    }
};