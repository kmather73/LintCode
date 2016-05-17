class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        int n = s.size();
        if(n == 0)
            return 0;

        std::vector<int> DP( n+2 );
        DP[0] = 0;
        DP[1] = 1;
        
        for(int i = 0; i < n; ++i){
            if(s[i] != '0')
                DP[i+2] += DP[i+1];
                
            if(i != 0 &&  (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6') ))
                DP[i+2] += DP[i];
        }
        
        return DP[n+1];
    }
};