class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> seats;
        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }
        if (seats.size() == 0 || seats.size() % 2 != 0) return 0;
        long long ans = 1;
        long long MOD = 1e9 + 7;
        for (int i = 2; i < seats.size(); i += 2) {
            int length = seats[i] - seats[i-1];
            ans = (ans * length) % MOD;
        }

        return (int)ans;
    }
};