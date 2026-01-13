class Solution {
    public:
        double separateSquares(vector<vector<int>>& squares) {
            double totalArea = 0;
            double minY = 2e9, maxY = 0;
            for (const auto& sq : squares) {
                double y = sq[1];
                double l = sq[2];
                totalArea += l * l;
                minY = min(minY, y);
                maxY = max(maxY, y + l);
            }
    
            double target = totalArea / 2.0;
            double low = minY, high = maxY;
            for (int i = 0; i < 100; ++i) {
                double mid = low + (high - low) / 2;
                double currentArea = 0;
                for (const auto& sq : squares) {
                    double y = sq[1];
                    double l = sq[2];
                    double top = y + l;
    
                    if (mid <= y) currentArea += 0;
                    else if (mid >= top) currentArea += l * l; 
                    else currentArea += (mid - y) * l;
                }
    
                if (currentArea >= target) high = mid;
                else low = mid;
            }
    
            return high;
        }
    };