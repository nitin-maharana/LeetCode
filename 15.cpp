/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempResult;
        int first, tempValue;
        int len, l, r;
        
        len = nums.size();
        
        sort(nums.begin(), nums.end());
            
        for(int i = 0; i < len-2;)
        {
            l = i+1;
            r = len-1;
            
            first = -1 * nums[i];
            
            while(l < r)
            {
                if(nums[l]+nums[r] == first)
                {
                    tempResult.push_back(nums[i]);
                    tempResult.push_back(nums[l]);
                    tempResult.push_back(nums[r]);
                    result.push_back(tempResult);
                    tempResult.clear();
                    
                    tempValue = nums[l];
                    
                    while(l < r)
                    {
                        l++;
                        if(nums[l] != tempValue)
                            break;
                    }
                    
                    tempValue = nums[r];
                    
                    while(l < r)
                    {
                        r--;
                        if(nums[r] != tempValue)
                            break;
                    }
                }
                else if(nums[l]+nums[r] > first)
                    r--;
                else
                    l++;
            }
            
            tempValue = nums[i];
            
            while(i < len-2)
            {
                i++;
                if(nums[i] != tempValue)
                    break;
            }
        }
        
        return result;
    }
};
