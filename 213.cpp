/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0)
            return 0;
        
        if(len == 1)
            return nums[0];
        
        int includeFirst, includeLast;
        
        pair<int, int> includeornot;
        int temp;
        
        includeornot = make_pair(0,0);
        
        for(int i = 0; i < len-1; i++)
        {
            temp = includeornot.second + nums[i];
            includeornot.second = max(includeornot.first, includeornot.second);
            includeornot.first = temp;
        }
        
        includeFirst = max(includeornot.first, includeornot.second);
        
        includeornot = make_pair(0,0);
        
        for(int i = 1; i < len; i++)
        {
            temp = includeornot.second + nums[i];
            includeornot.second = max(includeornot.first, includeornot.second);
            includeornot.first = temp;
        }
        
        includeLast = max(includeornot.first, includeornot.second);

        return max(includeFirst, includeLast);
    }
};