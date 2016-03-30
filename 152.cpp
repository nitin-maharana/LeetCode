/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int currMax, currMin, maxProd, temp;

        currMax = currMin = maxProd = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            temp = currMax;
            currMax = max(nums[i], max(currMax*nums[i], currMin*nums[i]));
            currMin = min(nums[i], min(temp*nums[i], currMin*nums[i]));
            maxProd = max(currMax, maxProd);
        }
        
        return maxProd;
    }
};