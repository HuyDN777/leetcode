class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1]; 
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int result = 0;
        
        for(int i = 0; i < boxTypes.size() && truckSize > 0; ++i) {
            int num = boxTypes[i][0];
            int unit = boxTypes[i][1];
            int take = min(num, truckSize);
            result += take * unit;
            truckSize -= take;
        }

        return result;
    }
};
