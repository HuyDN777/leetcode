class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int A = stoi(a[1]), B = stoi(b[1]);
            if (A != B) return A < B;
            return a[0] == "OFFLINE";
        }); 
        vector<int> ans(numberOfUsers, 0);
        vector<int> online_until(numberOfUsers, 0);

        for (const auto& ev : events) {
            string type = ev[0];
            int curTime = stoi(ev[1]);
            string content = ev[2];

            if (type == "OFFLINE") {
                int id = stoi(content);
                online_until[id] = curTime + 60;
            } 
            else {
                if (content == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        ans[i]++;
                    }
                } 
                else if (content == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (online_until[i] <= curTime) ans[i]++;
                    }
                } 
                else { 
                    stringstream ss(content);
                    string token;
                    while (ss >> token) {
                        int id = stoi(token.substr(2));
                        ans[id]++;
                    }
                }
            }
        }

        return ans;
    }
};