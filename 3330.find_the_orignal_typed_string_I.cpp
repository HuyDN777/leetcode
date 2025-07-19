class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        if(n == 0) return 1;
        
        int result = 1; 
        int i = 0;
        
        while(i < n) {
            char ch = word[i];
            int j = i;
            while(j < n && word[j] == ch) j++;
            int len = j - i;
            if(len > 1) result += (len - 1);
            i = j;
        }
        
        return result;
    }
};