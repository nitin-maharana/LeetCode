/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l, r, mid, len;
        
        len = nums.size();
        
        l = 0; r = len-1;
        
        while(l <= r)
        {
            mid = l + ((r-l) / 2);
            
            if(nums[mid] > nums[l] && nums[mid] < nums[r])
                return nums[l];
            
            if(mid-1 >= l)
            {
                if(nums[mid-1] > nums[mid])
                    return nums[mid];
            }
            else
                return min(nums[l], nums[r]);
            
            if(mid+1 <= r)
            {
                if(nums[mid+1] < nums[mid])
                    return nums[mid+1];
            }
            else
                return min(nums[l], nums[r]);
            
            if(nums[mid] > nums[l])
            {
                l = mid + 1;
                continue;
            }
            else
            {
                r = mid - 1;
                continue;
            }
        }
    }
};