class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        int n = stations.size();
        vector<long long> initial_power(n, 0);
        vector<long long> diff_initial(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            diff_initial[L] += stations[i];
            if (R + 1 < n + 1) {
                diff_initial[R + 1] -= stations[i];
            }
        }
        
        long long current_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_sum += diff_initial[i];
            initial_power[i] = current_sum;
        }

        long long low = 0;
        long long high = initial_power[0]; 
        for(long long p : initial_power) high = max(high, p);
        high += k; 
        
        long long max_min_power = 0;

        auto check = [&](long long target_power) -> bool {
            if (target_power <= 0) return true;
            
            long long k_used = 0;
            vector<long long> new_diff(n + 1, 0); 
        
            long long added_power_sum = 0;
            
            for (int i = 0; i < n; ++i) {
                added_power_sum += new_diff[i];

                long long total_current_power = initial_power[i] + added_power_sum;
                
                if (total_current_power < target_power) {
                    long long needed = target_power - total_current_power;
                    
                    if (k_used + needed > k) {
                        return false; 
                    }
                    
                    k_used += needed;
                
                    added_power_sum += needed;
                       
                    int end_index = i + 2 * r + 1;
                    if (end_index < n + 1) {
                        new_diff[end_index] -= needed;
                    }
                }
            }
            
            return true;
        };

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid)) {
                max_min_power = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        
        return max_min_power;
    }
};