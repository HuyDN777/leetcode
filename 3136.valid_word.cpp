class Solution {
public:
    bool isValid(string word) {
        int cntVowel = 0, cntConsonant = 0;
        if(word.length() < 3) return false;
        for(char& c : word) {
            if(!isdigit(c) && !isalpha(c)) return false;
            if(isdigit(c)) continue;
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cntVowel++;
            else cntConsonant++;
        }
        if(cntVowel >= 1 && cntConsonant >= 1) return true;
        return false;
    }
};