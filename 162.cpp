/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//O(logN)
class Solution {
    void findPeakElement(vector<int>& nums, int l, int r, int& index)
    {
        if(l > r)
            return;
        
        int mid = l + ((r - l) / 2);
        
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
        {
            index = mid;
            return;
        }
        
        findPeakElement(nums, l, mid-1, index);
        findPeakElement(nums, mid+1, r, index);
        
        return;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 1)
            return 0;
        
        if(1 < len && nums[0] > nums[1])
            return 0;
        
        if(len-2 >= 0 && nums[len-1] > nums[len-2])
            return len-1;
        
        int index = 0;
        
        findPeakElement(nums, 1, len-2, index);
        
        return index;
    }
};

//O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 1)
            return 0;
        
        if(1 < len && nums[0] > nums[1])
            return 0;
        
        if(len-2 >= 0 && nums[len-1] > nums[len-2])
            return len-1;
        
        for(int i = 1; i < len-1; i++)
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
    }
};