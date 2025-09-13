class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowel, consonant;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel[c]++;
            else consonant[c]++;
        }
        
        int maxVowelFreq = 0;
        if (!vowel.empty()) {
            auto maxVowelIt = max_element(vowel.begin(), vowel.end(), 
                                [](const auto &a, const auto &b) {
                                    return a.second < b.second;
                                });
            maxVowelFreq = maxVowelIt->second;
        }

        int maxConsonantFreq = 0;
        if (!consonant.empty()) {
            auto maxConsonantIt = max_element(consonant.begin(), consonant.end(), 
                                  [](const auto &a, const auto &b) {
                                      return a.second < b.second;
                                  });
            maxConsonantFreq = maxConsonantIt->second;
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};