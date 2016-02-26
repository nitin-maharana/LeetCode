/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if(!nums.size())
            return result;

        int curr = nums[0];
        int index = 0, i;
        
        for(i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] == nums[i] + 1)
                continue;
            else
            {
                if((i - index) > 0)
                    result.push_back(to_string(curr)+"->"+to_string(nums[i]));
                else
                    result.push_back(to_string(curr));
                curr = nums[i+1];
                index = i+1;
            }
        }
        
        if((i - index) > 0)
            result.push_back(to_string(curr)+"->"+to_string(nums[i]));
        else
            result.push_back(to_string(curr));
        
        return result;
    }
};