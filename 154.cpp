/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l, r, mid;
        
        l = 0;
        r = nums.size()-1;
        
        while(l < r)
        {
            if(nums[l] < nums[r])
                break;
                
            mid = l + (r - l) / 2;
            
            if(nums[mid] > nums[r])
                l = mid + 1;
            else if(nums[l] == nums[mid])
            {
                while(nums[l] == nums[mid] && l != mid)
                    l++;
                
                while(nums[r] == nums[mid] && r != mid)
                    r--;
            }
            else
                r = mid;
        }
        
        return nums[l];
    }
};