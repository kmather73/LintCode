class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        std::vector<int> merged;
        
        int i = 0;
        int j = 0;
        
        while ( i < A.size() && j < B.size() ) {
            if (A[i] < B[j])
                merged.push_back(A[i++]);
            else
                merged.push_back(B[j++]);
        }
        
        while ( i < A.size() )
            merged.push_back(A[i++]);
        
        while( j < B.size() )
            merged.push_back(B[j++]);
            
        return merged;
    }
};
