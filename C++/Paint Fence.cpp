class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        std::vector<int> dp(3);
        dp[0] = k;
        dp[1] = k + k*(k-1);
        
        for(int i=2; i < n; ++i)
            dp[i%3] = (k-1)*( dp[ (i-1)%3 ] +  dp[ (i-2)%3 ]);
            
        return dp[ (n-1)%3 ];
    }
};
