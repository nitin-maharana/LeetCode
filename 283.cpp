/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        int vacantIndex = 0;
        
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i])
                nums[vacantIndex++] = nums[i];
            else
                zeros++;
        }
        
        len--;
        
        while(zeros--)
        {
            nums[len--] = 0;
        }
    }
};
