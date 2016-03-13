/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        
        int first, second;

        first = second = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= first)
                first = nums[i];
            else if(nums[i] <= second)
                second = nums[i];
            else
                return true;
        }
        
        return false;
    }
};