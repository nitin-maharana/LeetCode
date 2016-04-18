/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
    	unordered_map<int, int> memory;
    	int result, sum;

    	result = sum = 0;

    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(memory.find(sum) == memory.end())
    			memory[sum] = i;

    		sum += nums[i];

    		if(memory.find(sum - k) != memory.end())
    			result = max(result, i+1-memory[sum-k]);
    	}

    	return result;
    }
};