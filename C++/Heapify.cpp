class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        int n = A.size()/2;
        
        for(int i = n; i >= 0; --i)
            minHeapify(A,i);
    }
    
    void minHeapify(std::vector<int> &A, int i) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int n = A.size();
        int min;
        
        if (left < n && A[left] < A[i] )
            min = left;
        else 
            min = i;
            
        if(right < n && A[right] < A[min] )
            min = right;
            
        if(min != i){
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            minHeapify( A, min);
        }
    }
};
