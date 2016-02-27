/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int len;
public:
    void rotate(vector<int>& nums, int k) {
        len = nums.size();
        
        if(!len)
            return;
        
        int number, temp, currIndex, nextIndex;
        int count, origin;
        
        currIndex = 0;
        number = nums[currIndex];
        count = len;
        origin = 0;
        
        while(count--)
        {
            nextIndex = ((currIndex+k) % len);
            temp = nums[nextIndex];
            nums[nextIndex] = number;
            number = temp;
            currIndex = nextIndex;
            
            if(currIndex == origin)
            {
                origin += 1;
                currIndex = origin;
                number = nums[currIndex];
            }
        }
    }
};

//One more solution using reverse.
class Solution {
    int len;
    
    void reverseArray(vector<int>& nums, int l, int r)
    {
        int t;
        
        while(l < r)
        {
            t = nums[l];
            nums[l++] = nums[r];
            nums[r--] = t;
        }
        
        return;
    }
public:
    void rotate(vector<int>& nums, int k) {
        len = nums.size();
        
        if(!len)
            return;
        
        k = k % len;
        reverseArray(nums, len-k, len-1);
        reverseArray(nums, 0, len-k-1);
        reverseArray(nums, 0, len-1);
    }
};