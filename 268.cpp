/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Using XOR.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int result = 0;
        
        for(int i = 1; i <= nums.size(); i++)
            result ^= (i ^ nums[i-1]);

        return result;
    }
};

//Using Summation.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        
        int wholeSum = (len * (len + 1)) / 2;

        int arraySum = 0;
        
        for(int i : nums)
            arraySum += i;
            
        return wholeSum - arraySum;
    }
};

//Using Summation. Optimized
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int result = 0;
            
        for(int i = 1; i <= nums.size(); i++)
            result += (i-nums[i-1]);

        return result;
    }
};