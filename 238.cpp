/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int countNumberOfZeroes(vector<int>& nums)
    {
        int count = 0;
        
        for(int i: nums)
            if(!i)
                count++;
        
        return count;
    }
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        
        if(countNumberOfZeroes(nums) > 1)
            return result;
        
        int leftProd, rightProd;
        
        leftProd = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            result[i] = leftProd;
            leftProd *= nums[i];
        }
        
        rightProd = 1;

        for(int i = nums.size()-1; i >= 0; i--)
        {
            result[i] = result[i] * rightProd;
            rightProd *= nums[i];
        }
        
        return result;
    }
};