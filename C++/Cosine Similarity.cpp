class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        if ( A.size() != B.size() )
            return 2;
            
        int normA = 0,  normB = 0, A_dot_B = 0;
        for(int i=0; i < A.size(); ++i){
            normA += A[i] * A[i];
            normB += B[i] * B[i];
            A_dot_B += A[i] * B[i];
        }
        
        if(normA == 0 || normB == 0)
            return 2;
            
        return A_dot_B / (std::sqrt(normA)  * std::sqrt(normB));
    }
};
