class Solution {
    public:
        int minimumPairRemoval(vector<int>& nums) {
            int operations = 0;
            
            while (true) {
                bool isSorted = true;
                for (size_t i = 0; i + 1 < nums.size(); ++i) {
                    if (nums[i] > nums[i + 1]) {
                        isSorted = false;
                        break;
                    }
                }
                
                if (isSorted) return operations;
                long long minSum = -1;
                int minIndex = -1;
    
                for (size_t i = 0; i + 1 < nums.size(); ++i) {
                    long long currentSum = (long long)nums[i] + nums[i + 1];
                    if (minIndex == -1 || currentSum < minSum) {
                        minSum = currentSum;
                        minIndex = i;
                    }
                }
    
                nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
                nums.erase(nums.begin() + minIndex + 1);
                operations++;
            }
        }
    };