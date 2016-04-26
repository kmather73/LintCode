class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        long long count = 0;
        std::vector<int> temp;
        temp.reserve( A.size() );
        
        
        return mergeSort(A, 0, A.size(), temp);
    }
    
    long long mergeSort(std::vector<int>& A, int start, int end, 
                    std::vector<int>& temp){
        if( end-1 <= start)
            return 0LL;
            
    
        //sort
        int mid = (end - start) / 2 + start;
        long long count = mergeSort(A, start, mid, temp);
        count += mergeSort(A, mid, end, temp);
        
        //merge
        int i = start;
        int j = mid;
        int k = start;
        
        while ( i < mid && j < end) {
            if( A[i] <= A[j] ){
                temp[k++] = A[i++];
            } else {
                count += mid-i;
                temp[k++] = A[j++];
            }
        }
        
        while ( i < mid )
            temp[k++] = A[i++];
            
        while ( j < end )
            temp[k++] = A[j++];
            
        for(i = start; i < end; ++i)
            A[i] = temp[i];
            
        return count;
    }
};