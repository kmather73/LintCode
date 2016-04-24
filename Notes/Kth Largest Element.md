This problem can be solved in a number of ways 

1) We can sort the array can pick the Kth last element, this will take O(n log n) time to sort.

2) We can run max-heapify on the array and then extract the first k elements which will take O(n + k log n)

3) We could use quick sorts partition function to partition the array unitll we get to the Kth largest element. This will take O(n).

Since the STL is well optimized we should just use std::algorithms::sort function to get the answer and the code will be quite short as well preform better then the other results.
