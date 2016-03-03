/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSumSoFar = INT_MIN;
        int currSum = 0;
        
        for(int i : nums)
        {
            currSum += i;
            
            if(currSum > maxSumSoFar)
                maxSumSoFar = currSum;
            
            currSum = (currSum < 0) ? 0 : currSum;
        }
        
        return maxSumSoFar;
    }
};