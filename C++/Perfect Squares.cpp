class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
       
        //Is n a perfect square 
        int sqrtOfn = std::sqrt( n );
        
        if(sqrtOfn * sqrtOfn  == n)
            return 1;
            
        //Do I need two squares
        for(int i = 1; i <= sqrtOfn; ++i){
            int remainder = n - i*i;
            int sqrtOfNum = std::sqrt(remainder);
            
            if(sqrtOfNum * sqrtOfNum == remainder)
                return 2;
        }
        
        
        //Do I need four squares
        int m = n;
        while( m%4 == 0 )
            m = m/4;
            
        if( m%8 == 7 )
            return 4;
        
        //Only need three squares
        return 3;
    }
};