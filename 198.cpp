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

        int memory[len];
        
        memory[0] = nums[0];
        
        if(len > 1)
            memory[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < len; i++)
            memory[i] = max(memory[i-1], nums[i]+memory[i-2]);
        
        return memory[len-1];
    }
};