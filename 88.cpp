/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)
            return;
            
        int index = m + n - 1;
        int ptr1, ptr2;
        
        ptr1 = m-1;
        ptr2 = n-1;
        
        while(ptr1 >= 0 && ptr2 >= 0)
            nums1[index--] = ((nums1[ptr1] > nums2[ptr2]) ? nums1[ptr1--] : nums2[ptr2--]);
            
        while(ptr2 >= 0)
            nums1[index--] = nums2[ptr2--];
    }
};