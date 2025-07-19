class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()) return s;        
        string result(s.length(), ' ');
        int index = 0;
        int step = 2 * (numRows - 1);
        for(int i = 0; i < numRows; ++i) {
            for(int j = i; j < s.length(); j += step) {
                result[index++] = s[j];
                if(i != 0 && i != numRows - 1) {
                    int mid = j + step - 2 * i;
                    if(mid < s.length()) result[index++] = s[mid];
                }
            }
        }
        
        return result;
    }
};