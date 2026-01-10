class Solution {
    public:
        int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
            int totalApples = 0;
            for (int a : apple) {
                totalApples += a;
            }
            
            sort(capacity.begin(), capacity.end(), greater<int>());
            
            int boxCount = 0;
            int currentCapacity = 0;
            
            for (int cap : capacity) {
                currentCapacity += cap;
                boxCount++;
                if (currentCapacity >= totalApples) return boxCount;
            }
            
            return boxCount;
        }
    };