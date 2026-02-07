class Solution {
    public:
        int minimumDeletions(string s) {
            int count_b = 0;
            int deletions = 0; 
            for (char c : s) {
                if (c == 'b') count_b++;
                else {
                    if (count_b > 0) {
                        deletions++; 
                        count_b--;  
                    }
                }
            }
            
            return deletions;
        }
    };