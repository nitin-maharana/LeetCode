/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Worst Case O(N)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l, r, mid;
        
        l = 0; r = nums.size()-1;
        
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            
            if(nums[mid] == target)
                return true;
            
            if(target > nums[mid])
            {
                if(target <= nums[r])
                    l = mid + 1;
                else
                    r--;
            }
            else
            {
                if(target >= nums[l])
                    r = mid-1;
                else
                    l++;
            }
        }
        
        return false;
    }
};

//O(logN)
class Solution {
    bool search(vector<int>& nums, int l, int r, int target)
    {
        if(l > r)
            return false;
        
        int mid = l + (r - l) / 2;
        
        if(nums[mid] == target)
            return true;
        
        return (search(nums, l, mid-1, target) || search(nums, mid+1, r, target));
    }
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
};