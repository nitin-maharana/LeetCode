/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = nums[0];
        int count = 1;
        
        for(int i : nums)
        {
            if(i == majorityElement)
                count++;
            else
            {
                count--;
                if(count == 0)
                {
                    majorityElement = i;
                    count = 1;
                }
            }
        }
        
        return majorityElement;
    }
};
