class Solution {
public:
    int reverse(int x) {
        long long y = abs((long long)x);
        long long res = 0;
        
        while(y != 0) {
            res = res * 10 + y % 10;
            y /= 10;
        }
        
        if(res > INT_MAX || res < INT_MIN) return 0;
        
        if(x < 0) return -res; 
        else return res;
    }
};