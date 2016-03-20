/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
            return;

        int len = nums.size();
        int maxx = nums[len-1];

        for(int i = len-2; i >= 0; i--)
        {
            if(nums[i] >= maxx)
                maxx = nums[i];
            else
            {
                reverse(nums.begin()+i+1, nums.end());

                for(int j = i+1; j < len; j++)
                {
                    if(nums[j] > nums[i])
                    {
                        swap(nums[i], nums[j]);
                        return;
                    }
                }
            }
        }

        reverse(nums.begin(), nums.end());
        
        return;
    }
};