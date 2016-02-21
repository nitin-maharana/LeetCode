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

    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        int len = nums.size();
        
        unordered_set<int> memory;
        
        int startIndex, endIndex;
        
        startIndex = 0;
        endIndex = k;
        
        for(int i = startIndex; i <= endIndex && i < len; i++)
        {
            if(memory.find(nums[i]) != memory.end())
                return true;
            else
                memory.insert(nums[i]);
        }
        
        endIndex++;
        
        while(endIndex < len)
        {
            memory.erase(nums[startIndex]);
            
            startIndex++;
            
            if(memory.find(nums[endIndex]) != memory.end())
                return true;
            else
                memory.insert(nums[endIndex]);
            
            endIndex++;
        }
        
        return false;
    }
};