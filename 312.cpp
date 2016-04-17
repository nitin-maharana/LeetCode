/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int len = nums.size();
        
        vector<vector<int>> memory(len, vector<int>(len, 0));
        
        for(int n = 1; n <= len-2; n++)
        {
            for(int l = 0; l < len-n-1; l++)
            {
                int r = l + n + 1;
                
                for(int i = l+1; i < r; i++)
                    memory[l][r] = max(memory[l][r], memory[l][i]+memory[i][r]+nums[l]*nums[i]*nums[r]);
            }
        }
        
        return memory[0][len-1];
    }
};