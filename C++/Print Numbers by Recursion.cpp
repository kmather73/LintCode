class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        std::vector<int> nums;
        if(n == 0)
            return nums;
        else if(n == 1){
            for(int i = 1; i < 10; ++i)
                nums.push_back(i);
            return nums;
        }
        
        std::vector<int> moreNums = numbersByRecursion(n-1);
        int powTen = std::pow(10, n-1);
        
        for(int i=0; i < 10; ++i){
            for(int num : moreNums)
                nums.push_back( i*powTen + num);
            nums.push_back( (1+i)*powTen );
        }
        nums.pop_back();
        
        
        return nums;
    }
};
