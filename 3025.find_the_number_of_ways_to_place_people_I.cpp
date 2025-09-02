class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int Ax = points[i][0], Ay = points[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int Bx = points[j][0], By = points[j][1];
                if (Ax <= Bx && Ay >= By) {
                    bool ok = true;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        int px = points[k][0], py = points[k][1];
                        if (Ax <= px && px <= Bx && By <= py && py <= Ay) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) ans++;
                }
            }
        }
        return ans;   
    }
};