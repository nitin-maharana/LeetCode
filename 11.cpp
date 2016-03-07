/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l, r, maxArea, currArea;
        
        l = 0;
        r = height.size()-1;
        maxArea = 0;
        
        while(l < r)
        {
            currArea = (r-l) * min(height[l], height[r]);
            
            maxArea =  (currArea > maxArea) ? currArea : maxArea;
            
            if(height[l] > height[r])
            {
                r--;
                
                while((l < r) && (height[r] < height[r+1]))
                    r--;
            }
            else
            {
                l++;
                
                while((l < r) && (height[l] < height[l-1]))
                    l++;
            }
        }
        
        return maxArea;
    }
};