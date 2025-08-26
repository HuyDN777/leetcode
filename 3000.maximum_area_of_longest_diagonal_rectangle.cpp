class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        double maxDiagonal = 0.0;
        
        for (auto &dim : dimensions) {
            int w = dim[0], h = dim[1];
            double d = sqrt(1.0 * w * w + 1.0 * h * h);
            int area = w * h;
            
            if (d > maxDiagonal) {
                maxDiagonal = d;
                ans = area;
            } else if (d == maxDiagonal) {
                ans = max(ans, area);
            }
        }
        return ans;
    }
};
