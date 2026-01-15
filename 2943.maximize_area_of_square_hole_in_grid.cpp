class Solution {
    public:
        int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
            sort(hBars.begin(), hBars.end());
            sort(vBars.begin(), vBars.end());
    
            int maxH = 1, currentH = 1;
            for (size_t i = 1; i < hBars.size(); ++i) {
                if (hBars[i] == hBars[i - 1] + 1) currentH++;
                else {
                    maxH = max(maxH, currentH);
                    currentH = 1;
                }
            }
            maxH = max(maxH, currentH);
    
            int maxV = 1, currentV = 1;
            for (size_t i = 1; i < vBars.size(); ++i) {
                if (vBars[i] == vBars[i - 1] + 1) currentV++;
                else {
                    maxV = max(maxV, currentV);
                    currentV = 1;
                }
            }
            maxV = max(maxV, currentV);
            int side = min(maxH + 1, maxV + 1);
            return side * side;
        }
    };