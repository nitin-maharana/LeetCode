/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int resultDiff, resultSum, currSum, currDiff;
        int len, l, r;
        
        len = nums.size();
        resultDiff = INT_MAX;
        resultSum = nums[0]+nums[1]+nums[2];
        
        for(int i = 0; i < len-2; i++)
        {
            l = i+1;
            r = len-1;
            
            while(l < r)
            {
                currSum = nums[i] + nums[l] + nums[r];
                currDiff = abs(currSum - target);
                
                if(currDiff < resultDiff)
                {
                    resultDiff = currDiff;
                    resultSum = currSum;
                }
                
                if(l+1 < r && abs(currSum-nums[l]+nums[l+1]-target) < currDiff)
                {
                    l++;
                    
                    while(l+1 < r && nums[l] == nums[l+1])
                        l++;
                }
                else
                {
                    r--;
                    
                    while(r-1 > l && nums[r] == nums[r-1])
                        r--;
                }
            }
        }
        
        return resultSum;
    }
};