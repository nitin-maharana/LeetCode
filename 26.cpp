/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        
        if(len < 2)
            return len;
            
        int current = nums[0];
        int index = 1;
        
        for(int i = 1; i < len; i++)
        {
            if(nums[i] != current)
            {
                current = nums[i];
                nums[index++] = current;
            }
        }
        
        return index;
    }
};