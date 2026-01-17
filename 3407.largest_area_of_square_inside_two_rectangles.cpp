class Solution {
    public:
        long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
            long long maxSide = 0;
            int n = bottomLeft.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int intersectLeft = max(bottomLeft[i][0], bottomLeft[j][0]);
                    int intersectBottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                    int intersectRight = min(topRight[i][0], topRight[j][0]);
                    int intersectTop = min(topRight[i][1], topRight[j][1]);
                    if (intersectLeft < intersectRight && intersectBottom < intersectTop) {
                        int width = intersectRight - intersectLeft;
                        int height = intersectTop - intersectBottom;
                        int currentSide = min(width, height);
                        if (currentSide > maxSide) maxSide = currentSide;
                    }
                }
            }
            return maxSide * maxSide;
        }
    };