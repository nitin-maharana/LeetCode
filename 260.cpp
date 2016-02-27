/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Using bit manipulation(XOR).
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allxor = 0;
        
        for(int i: nums)
            allxor ^= i;

        int lastSetBit = allxor & (allxor*-1);
        vector<int> result;
        
        result.push_back(0);
        result.push_back(0);
        
        for(int i: nums)
        {
            if(i & lastSetBit)
                result[0] ^= i;
            else
                result[1] ^= i;
        }
        
        return result;
    }
};