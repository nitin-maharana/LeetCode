/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//O(N) Solution. Finding cycle method.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        
        slow = 0;
        fast = 0;
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = 0;
        
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;
        
    }
};

//O(NlogN) Solution. Using binary search.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l, r, mid;
        
        l = 1;
        r = nums.size();
        
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            
            int count = 0;
            
            for(int i : nums)
                if(i <= mid)
                    count++;
            
            if(count <= mid)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return l;
    }
};