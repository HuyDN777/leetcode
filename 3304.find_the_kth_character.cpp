class Solution {
public:
    char kthCharacter(int k) {
        int steps = 0;
        int len = 1;

        while(len < k) {
            len *= 2;
            steps++;
        }

        char c = 'a';
        while(steps--) {
            len /= 2;
            if(k > len) {
                k -= len;
                c = (c == 'z') ? 'a' : c + 1;
            }
        }

        return c;
    }
};