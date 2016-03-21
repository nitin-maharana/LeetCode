/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//By Implementing sorting algo.
class Solution {
    void mysort(vector<int>& nums, int l, int r)
    {
        if(l >= r)
            return;
        
        int i = r;
        
        for(int j = r-1; j >= l; j--)
        {
            if(nums[j] >= nums[r])
            {
                swap(nums[j], nums[i-1]);
                i--;
            }
        }
        
        swap(nums[i], nums[r]);
        
        mysort(nums, l, i-1);
        mysort(nums, i+1, r);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        mysort(nums, 0, nums.size()-1);
        
        return nums[nums.size()-k];
    }
};

//Using STL sort.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size()-k];
    }
};