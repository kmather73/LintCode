class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> maxElements;
        std::map<int, int> rbTree;

        for(int i = 0; i < n; ++i) {
            if(i >= k && rbTree[ nums[i-k] ] == i-k)
                rbTree.erase( nums[i-k] );
            
            rbTree[ nums[i] ] = i;
            
            if(i >= k-1) {
                int max = rbTree.rbegin()->first;
                maxElements.push_back( max );
            }
        }
        
        return maxElements;
    }
};