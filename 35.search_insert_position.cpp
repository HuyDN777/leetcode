class Solution {
public:
    int binarySearch(vector<int>& nums, int value) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(value > nums[mid]) low = mid + 1;
            else if(value < nums[mid]) high = mid - 1;
            else return mid;
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        if(binarySearch(nums, target) == -1) {
            for(int i = 0; i < nums.size(); i++) {
                if(target < nums[i]) return i;
            }
            return nums.size();
        }
        return binarySearch(nums, target);
    }
};