class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int res = 1;
        vector<int> up(arr.size(), 1), down(arr.size(), 1);
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i - 1] < arr[i]) {
                up[i] = down[i - 1] + 1;
                down[i] = 1;
            }
            else if(arr[i - 1] > arr[i]) {
                down[i] = up[i - 1] + 1;
                up[1] = 1;
            }
            else up[i] = down[i] = 1;
            res = max(res, max(up[i], down[i]));
        }
        return res;
    }
};