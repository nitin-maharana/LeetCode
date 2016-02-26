/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l, r, mid;
        
        l = 0; r = n-1;
        
        while(l < r)
        {
            mid = l + ((r-l+1) / 2);
            
            if(isBadVersion(mid))
                r = mid-1;
            else
                l = mid+1;
        }
        
        if(isBadVersion(l))
            return l;
        else
            return l+1;
    }
};