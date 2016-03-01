/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones, twos, threes;
        
        ones = twos = threes = 0;
        
        for(int i : nums)
        {
            twos |= (ones & i);
            
            ones ^= i;
            
            threes = (ones & twos);
            
            ones &= (~threes);
            twos &= (~threes);
        }
        
        return ones;
    }
};
