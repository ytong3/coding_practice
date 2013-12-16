class Solution {
public:
    int reverse(int x) {
        int r = 0;

        while(x != 0) {
            r = r*10 + x % 10;
            x /= 10;//note the difference between using a base. this is much more clean and less verbose. Actually it looks like the bit shift operation.
        }
        return r;
    }
};