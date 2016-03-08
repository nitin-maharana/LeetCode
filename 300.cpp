/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//O(N*N) using DP.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        if(!len)
            return 0;
        
        vector<int> memory(len, 1);
        
        int maxLenLIS = 1;
        
        for(int i = 1; i < len; i++)
        {
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i])
                    memory[i] = max(memory[i], memory[j]+1);

            maxLenLIS = max(maxLenLIS, memory[i]);
        }
        
        return maxLenLIS;
    }
};