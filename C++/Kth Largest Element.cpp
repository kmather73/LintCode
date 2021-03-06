//Runtime is O(n log n) can get O(K) but STL is optimized so this runs faster
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        std::sort(nums.begin(), nums.end());
        return nums[ nums.size() - k ];
    }
};
