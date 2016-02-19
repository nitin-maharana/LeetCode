/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        if(!len)
            return 0;

        if(len > 1)
            nums[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < len; i++)
            nums[i] = max(nums[i-1], nums[i]+nums[i-2]);
        
        return nums[len-1];
    }
};