class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);
        int ones = 0;
        int steps = 0;

        for(int i = 0; i < boxes.size(); i++) {
           ones += boxes[i]-'0';
           ans[i] +=steps;
           steps += ones;
        }
        ones = 0;
        steps = 0;
        for(int i = boxes.size() - 1; i >= 0; i--) {
            ones += boxes[i]-'0';
            ans[i] += steps;
            steps += ones;
        }
        return ans;
    }
};