/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        
        int candidate1, candidate2, count1, count2;
        
        candidate1 = candidate2 = count1 = count2 = 0;
        
        for(int i : nums)
        {
            if(count1 == 0 && i != candidate2)
            {
                candidate1 = i;
                count1++;
            }
            else if(i == candidate1)
                count1++;
            else if(count2 == 0 || i == candidate2)
            {
                candidate2 = i;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        
        for(int i : nums)
        {
            if(i == candidate1)
                count1++;
            else if(i == candidate2)
                count2++;
        }
        
        if(count1 > (nums.size() / 3))
            result.push_back(candidate1);
        
        if(count2 > (nums.size() / 3))
            result.push_back(candidate2);
        
        return result;
    }
};