/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    void searchRange(vector<int>& nums, vector<int>& result, int target, int l, int r)
    {
        if(l > r)
            return;
        
        int mid = l + ((r - l) / 2);
        
        if(nums[mid] == target)
        {
            if(mid-1 < 0 || nums[mid-1] != target)
                result[0] = mid;
            
            if(mid+1 >= nums.size() || nums[mid+1] != target)
                result[1] = mid;
            
            if(result[0] == -1)
                searchRange(nums, result, target, l, mid-1);
            
            if(result[1] == -1)
                searchRange(nums, result, target, mid+1, r);
            
            return;    
        }
        
        if(target > nums[mid])
            searchRange(nums, result, target, mid+1, r);
        else
            searchRange(nums, result, target, l, mid-1);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        
        result.push_back(-1);
        result.push_back(-1);
        
        if(nums.size() == 0)
            return result;
        
        searchRange(nums, result, target, 0, nums.size()-1);
        
        return result;
    }
};