class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        stack<string> parentheses;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') parentheses.push(s[i] + to_string(i));
            else if(s[i] == ')') {
                string top = parentheses.top().substr(1);
                parentheses.pop();
                reverse(s.begin() + stoi(top) + 1, s.begin() + i);
            }
        }
        for(char c : s) {
            if(c != '(' && c != ')') result += c;
        }
        return result;
    }
};