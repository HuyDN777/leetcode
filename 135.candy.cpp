class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int total = 1;
        while(i < n) {
            if(ratings[i] == ratings[i - 1]) {
                total += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                total += peak;
                i++;
            }

            int down = 1;
            while(i  < n && ratings[i] < ratings[i - 1]) {
                i++;
                total += down;
                down++;
            }

            if(peak < down) total += (down - peak);
        }
        return total;
    }
};