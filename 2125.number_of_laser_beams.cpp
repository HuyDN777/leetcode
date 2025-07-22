class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0, n = bank.size(), prev = 0;
        for(string& s: bank) {
            int curr = count(s.begin(), s.end(), '1');
            if(!curr)
                continue;
            
            totalBeams += prev * curr;
            prev = curr;
        }
        return totalBeams;
    }
};