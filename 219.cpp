/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int len;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        
        unordered_map<int,int> memory;
        
        for(int i = 0; i < len; i++)
        {
            if(memory.find(nums[i]) != memory.end() && (i - memory[nums[i]]) <= k)
                return true;
            else
                memory[nums[i]] = i;
        }

        return false;
    }
};