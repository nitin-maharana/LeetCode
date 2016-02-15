/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> memory;
        
        for(int i : nums)
            memory.insert(i);
        
        if(memory.size() != nums.size())
            return true;
        else
            return false;
    }
};
