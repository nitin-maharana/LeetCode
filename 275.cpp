/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l, r, mid, len;
        
        len = citations.size();
        l = 0;
        r = len-1;

        while(l <= r)
        {
            mid = l + (r - l) / 2;
            
            if(citations[mid] >= len-mid)
                r = mid-1;
            else
                l = mid+1;
        }
        
        return len-l;
    }
};