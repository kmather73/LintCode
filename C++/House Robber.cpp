class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        int n = A.size()+1;
        std::vector<long long> DP(3);
        DP[0] = 0;
        DP[1] = A[0];
        
        for (int i = 2; i < n; ++i) {
            DP[i%3] = std::max( DP[(i-1)%3], DP[(i-2)%3] + A[i-1]);
        }
        
        return DP[(n-1)%3];
    }
};