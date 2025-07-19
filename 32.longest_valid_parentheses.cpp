class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt  = 0;
        stack<int> X;
        X.push(-1);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') X.push(i);
            else {
                X.pop();
                if(X.size() > 0) cnt = max(cnt, i - X.top());
                if(X.empty()) X.push(i);
            }
        }
        return cnt;
    }
};