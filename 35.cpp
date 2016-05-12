/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l, r, mid;
        
        l = 0;
        r = nums.size()-1;
        
        while(l < r)
        {
            mid = l + ((r - l) / 2);
            
            if(target == nums[mid])
                return mid;

            if(target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        if(target == nums[l])
            return l;
    
        if(target > nums[l])
            return l+1;
        else
            return l;
    }
};
