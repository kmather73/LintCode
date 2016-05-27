class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        else if (n < 0) return 1/myPow(x, -n);
        
        double temp = myPow(x, n/2);
        double ans = temp*temp;
        
        if( n%2 == 1) {
            ans *= x;
        }
        
        return ans;
    }
};