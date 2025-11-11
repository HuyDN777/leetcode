class Solution {
private:
    int calculate_x_sum(const vector<int>& subarray, int x) {
        map<int, int> freq_map;
        for (int val : subarray) {
            freq_map[val]++;
        }
        vector<pair<int, int>> elements;
        for (auto const& [val, freq] : freq_map) {
            elements.push_back({val, freq});
        }
        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });

        int x_sum = 0;
        int top_count = 0;
        for (const auto& p : elements) {
            if (top_count >= x) {
                break;
            }
            int val = p.first;
            int freq = p.second;
            
            x_sum += val * freq;
            top_count++;
        }
        
        return x_sum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        if (n < k) return {}; 
        
        vector<int> answer;
        for (int i = 0; i <= n - k; ++i) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            int current_x_sum = calculate_x_sum(subarray, x);
            answer.push_back(current_x_sum);
        }
        
        return answer;
    }
};