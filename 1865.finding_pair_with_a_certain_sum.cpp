class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) freq2[num]++;
    }

    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (int num1 : nums1) {
            int complement = tot - num1;
            cnt += freq2[complement];
        }
        return cnt;
    }
};