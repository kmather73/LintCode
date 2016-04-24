class Solution {
    public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long zeros =0;
        n = n/5;

        while (n != 0) {
            zeros += n;
            n /= 5;
        }

        return zeros;
    }
};
