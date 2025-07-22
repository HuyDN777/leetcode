class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, tmp = capacity;
        for(int i = 0; i < plants.size(); i++) {
            if(capacity >= plants[i]) {
                steps++;
                capacity -= plants[i];
            }
            else {
                steps += 2 * i + 1;
                capacity = tmp;
                capacity -= plants[i];
            }
        }
        return steps;
    }
};