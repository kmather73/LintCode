class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0)
            return 0;
            
        std::vector<std::vector<int>> DP(2, std::vector<int>(3));
        DP[0][0] = costs[0][0];
        DP[0][1] = costs[0][1];
        DP[0][2] = costs[0][2];
        
        for(int i=1; i < costs.size(); ++i){
            DP[i%2][0] = costs[i][0] + std::min(DP[ (i-1)%2 ][1], DP[ (i-1)%2][2] );
            DP[i%2][1] = costs[i][1] + std::min(DP[ (i-1)%2 ][0], DP[ (i-1)%2][2] );
            DP[i%2][2] = costs[i][2] + std::min(DP[ (i-1)%2 ][0], DP[ (i-1)%2][1] );
        }
        int n = costs.size()-1;
        return std::min( std::min(DP[ n%2 ][0], DP[ n%2 ][1]), DP[ n%2 ][2] );
        
    }
};
