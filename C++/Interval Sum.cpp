/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        std::vector<long long> sums;
        sums.push_back(0);
        
        for(int i = 0; i < A.size(); ++i)
            sums.push_back( sums[i] + A[i] );
        
        std::vector<long long> qSums;
        for(auto i : queries)
            qSums.push_back( sums[1 + i.end] - sums[i.start] );
            
        return qSums;
    }
};
