class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;

        int i = 0;
        
        while(i < s.length() && s[i] == ' ') i++;

        int sign = 1;
        if(s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            i++;
        }
        long long result = 0;
        while(i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return static_cast<int>(result * sign);
    }  
};