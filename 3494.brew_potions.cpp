class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        if (n == 0 || m == 0) return 0;
        vector<long long> prev_prefix(n, 0);
        long long run = 0;
        for (int i = 0; i < n; ++i) {
            run += 1LL * skill[i] * mana[0];
            prev_prefix[i] = run;
        }

        long long s_prev = 0; 
        for (int j = 1; j < m; ++j) {
            long long delta = LLONG_MIN;
            long long prefix_curr_i_minus1 = 0;
            long long running = 0;
            for (int i = 0; i < n; ++i) {
                running += 1LL * skill[i] * mana[j];
                long long term = prev_prefix[i] - prefix_curr_i_minus1;
                if (term > delta) delta = term;
                prefix_curr_i_minus1 = running; 
            }
            s_prev += delta;

            long long run2 = 0;
            for (int i = 0; i < n; ++i) {
                run2 += 1LL * skill[i] * mana[j];
                prev_prefix[i] = run2;
            }
        }

        return s_prev + prev_prefix[n-1];
    }
};
