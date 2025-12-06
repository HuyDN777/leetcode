class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;
        map<pair<int, int>, map<long long, int>> slopeMap;
        map<pair<int, int>, map<long long, int>> vectorMap;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(abs(dx), abs(dy));
                int s_dx = dx / g;
                int s_dy = dy / g;
                if (s_dx < 0 || (s_dx == 0 && s_dy < 0)) {
                    s_dx = -s_dx;
                    s_dy = -s_dy;
                }
                long long intercept = 1LL * s_dy * points[i][0] - 1LL * s_dx * points[i][1];
                slopeMap[{s_dx, s_dy}][intercept]++;
                 int v_dx = dx;
                 int v_dy = dy;
                 if (v_dx < 0 || (v_dx == 0 && v_dy < 0)) {
                    v_dx = -v_dx;
                    v_dy = -v_dy;
                 }
                 vectorMap[{v_dx, v_dy}][intercept]++;
            }
        }

        long long totalTrapezoids = 0;
        long long parallelograms = 0;
        for (auto& [slope, lines] : slopeMap) {
            long long totalSegments = 0;
            long long sumSq = 0;
            for (auto& [intercept, count] : lines) {
                totalSegments += count;
                sumSq += 1LL * count * count;
            }
            totalTrapezoids += (totalSegments * totalSegments - sumSq) / 2;
        }

        for (auto& [vec, lines] : vectorMap) {
            long long totalSegments = 0;
            long long sumSq = 0;
            for (auto& [intercept, count] : lines) {
                totalSegments += count;
                sumSq += 1LL * count * count;
            }
            parallelograms += (totalSegments * totalSegments - sumSq) / 2;
        }

        return totalTrapezoids - (parallelograms / 2);
    }
};