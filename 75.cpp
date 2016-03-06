/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//1-Pass Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex, twoIndex;
        
        for(zeroIndex = 0; zeroIndex < nums.size() && nums[zeroIndex] == 0; zeroIndex++);
        
        for(twoIndex = nums.size()-1; twoIndex >= 0 && nums[twoIndex] == 2; twoIndex--);
        
        int currIndex = zeroIndex;
        
        while(currIndex <= twoIndex)
        {
            if(nums[currIndex] == 0)
            {
                nums[currIndex++] = nums[zeroIndex];
                nums[zeroIndex] = 0;
                zeroIndex++;
            }
            else if(nums[currIndex] == 2)
            {
                nums[currIndex] = nums[twoIndex];
                nums[twoIndex] = 2;
                twoIndex--;
            }
            else
                currIndex++;
        }
    }
};

//2-Pass Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        
        for(int i : nums)
            count[i]++;
        
        int index = 0;
        
        for(int i = 0; i < count[0]; i++)
            nums[index++] = 0;
        
        for(int i = 0; i < count[1]; i++)
            nums[index++] = 1;
        
        for(int i = 0; i < count[2]; i++)
            nums[index++] = 2;
    }
};