/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Recursive Solution.
class Solution {
    vector<vector<int>> result;
    int len;
    
    void permute(vector<int>& nums, string& present, vector<int>& tempResult, int i)
    {
        if(i == len)
        {
            result.push_back(tempResult);
            return;
        }
        
        for(int j = 0; j < len; j++)
        {
            if(present[j] == '0')
            {
                present[j] = '1';
                tempResult[i] = nums[j];
                permute(nums, present, tempResult, i+1);
                present[j] = '0';
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        
        if(!len)
            return result;

        string present(len, '0');
        vector<int> tempResult(len);
        
        permute(nums, present, tempResult, 0);
        
        return result;
    }
};