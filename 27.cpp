/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = -1;
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == val)
            {
                index = i;
                break;
            }
        }
        
        if(index == -1)
            return len;
            
        for(int i = index+1; i < len; i++)
            if(nums[i] != val)
                nums[index++] = nums[i];

        return index;
    }
};