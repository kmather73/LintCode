class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int max = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp = subSquare(matrix, i, j);
                j += std::max(0, temp-1);
                max = std::max(max, temp);
            }
        }
        
        return max*max;
    }
    
    int subSquare(vector<vector<int> > &matrix, int row, int col){
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool onlyOnes = true;
        int len = 0;
        
        while(onlyOnes && row+len < n && col+len < m) {
            for(int i = 0; i <= len; ++i){
                onlyOnes &= (matrix[row+len][col+i] == 1);
            }
            
            for(int i = 0; i <= len; ++i){
                onlyOnes &= (matrix[row+i][col+len] == 1);
            }
            
            if( onlyOnes)
                ++len;
        }
        
        return len;
    }
};