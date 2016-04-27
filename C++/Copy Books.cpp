//O(n^2 * k) time  O(n*k) space
class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        k = std::min( k, n);
        
        std::vector< std::vector<int> > DP (n, std::vector<int>(k));
        std::vector< int > leftSums(n);
        
        leftSums[0] = DP[0][0] = pages[0];
        for(int i = 1; i < n; ++i)
            leftSums[i] = DP[i][0] = DP[i-1][0] + pages[i];

        //i == number of pages
        //j == number of people
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < k; ++j) {
                DP[i][j] = INT_MAX;
                for (int m = 0; m < i; ++m)
                    DP[i][j] = std::min( DP[i][j],
                                        std::max( DP[m][j-1], leftSums[i] - leftSums[m] ) );
            }
        }
        return DP[n-1][k-1];
    }
};