class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int cnt = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        for(int i = 0, j = 0; i < players.size() && j < trainers.size(); i++, j++) {
            while(j < trainers.size() && players[i] > trainers[j]) j++;
            if(j < trainers.size()) cnt++;
        }
        return cnt;
    }
};