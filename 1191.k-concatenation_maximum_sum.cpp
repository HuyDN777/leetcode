class Solution {
public:
    const int MOD = 1e9 + 7;

    long long kadane(const vector<int>& arr) {
        long long max_ending_here = 0, max_so_far = 0;
        for(int x : arr) {
            max_ending_here = max((long long)x, max_ending_here + x);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long total_sum = accumulate(arr.begin(), arr.end(), 0LL);

        long long max_kadane_once = kadane(arr);

        if(k == 1) return max_kadane_once % MOD;

        long long prefix_sum = 0, prefix_max = 0;
        for(int x : arr) {
            prefix_sum += x;
            prefix_max = max(prefix_max, prefix_sum);
        }

        long long suffix_sum = 0, suffix_max = 0;
        for(int i = arr.size() - 1; i >= 0; --i) {
            suffix_sum += arr[i];
            suffix_max = max(suffix_max, suffix_sum);
        }

        long long result = 0;
        if(total_sum > 0) {
            result = prefix_max + suffix_max + (k - 2) * total_sum;
        } else {
            result = max(prefix_max + suffix_max, max_kadane_once);
        }

        return result % MOD;
    }
};
