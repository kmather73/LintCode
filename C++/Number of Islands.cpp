class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        if(grid.size() == 0) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if( grid[i][j] ){
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<bool>>& grid, int i, int j){
        if( i<0 || j<0) return;
        else if( i >= grid.size() || j >= grid[0].size()) return;
        
        if( grid[i][j] ){
            grid[i][j] = false;
            for(int k=0; k<4; ++k){
                dfs(grid, i+dx[k], j+dy[k]);
            }
        }
    }
};