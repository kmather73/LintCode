class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if ( nums[i] != 0 ){
                nums[left++] = nums[i];
            }
        }
        
        for(int i = left; i < nums.size(); ++i){
            nums[i] = 0;
        }
    }
};