class Solution {
public:
    struct CompareGain {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            double gainA = (double)(a[0] + 1) / (a[1] + 1) - (double)a[0] / a[1];
            double gainB = (double)(b[0] + 1) / (b[1] + 1) - (double)b[0] / b[1];
            return gainA < gainB; 
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, CompareGain> pq;
        for (auto &c : classes) pq.push(c);

        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            top[0]++; top[1]++; 
            pq.push(top);
        }

        double ans = 0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans += (double)top[0] / top[1];
        }
        return ans / classes.size();
    }
};
