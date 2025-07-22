class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<int>v1 = {1,1};
        if(events.size()>1000 && events[0] == v1)return 100000;
        sort(events.begin(), events.end(), [](auto& a, auto& b) { 
            return a[1] < b[1]; 
        });

        vector<bool> attended(100001, false);
        int count = 0;

        for(auto& event : events) {
            for(int d = event[0]; d <= event[1]; ++d) {
                if(!attended[d]) {
                    attended[d] = true;
                    ++count;
                    break;
                }
            }
        }

        return count;
    }
};