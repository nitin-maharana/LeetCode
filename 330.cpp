/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        unsigned int count, sum, next, i;
        
        count = sum = i = 0;
        
        while(i < nums.size() && sum < n)
        {
            next = sum + 1;
            
            if(nums[i] <= next)
                sum += nums[i++];
            else
            {
                sum += next;
                count++;
            }
        }
        
        while(sum < n)
        {
            sum += (sum+1);
            count++;
        }
        
        return count;
    }
};