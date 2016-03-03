/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Kadane's Algorithm
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

//Divide and Conquer
class Solution {
    int maxSubFromCross(vector<int>& nums, int l, int m, int r)
    {
        int left = INT_MIN;
        int currSum = 0;
        
        for(int i = m; i >= l; i--)
        {
            currSum += nums[i];
            
            if(currSum > left)
                left = currSum;
        }
        
        int right = INT_MIN;
        currSum = 0;
        
        for(int i = m+1; i <= r; i++)
        {
            currSum += nums[i];
            
            if(currSum > right)
                right = currSum;
        }
        
        return (left + right);
    }
    
    int maxSubArray(vector<int>& nums, int l, int r)
    {
        if(l == r)
            return nums[l];
        
        int m = l + ((r-l)/2);
        
        return max(max(maxSubArray(nums, l, m), maxSubArray(nums, m+1, r)), maxSubFromCross(nums, l, m, r));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
};