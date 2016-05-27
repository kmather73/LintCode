class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int n = nums.size();
        int missing = n;
        
        for (int i = 0; i < n; ++i) {
            missing ^= i^nums[ i ];
        }
        
        return missing;
    }
};