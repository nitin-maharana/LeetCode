/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    
    void permuteUnique(vector<int>& nums, string& memory, vector<int>& tempResult, vector<vector<int>>& result, int i, int n)
    {
        if(i == n)
        {
            result.push_back(tempResult);
            return;
        }
        
        int j = 0;
        
        do{
            if(memory[j] == '0')
            {
                tempResult[i] = nums[j];
                memory[j] = '1';
                permuteUnique(nums, memory, tempResult, result, i+1, n);
                memory[j] = '0';
            
                j++;
            
                while(j < n)
                {
                    if(nums[j] != nums[j-1])
                        break;
                    j++;
                }
            }
            else
                j++;
        }while(j < n);
        
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        string memory(nums.size(), '0');
        
        vector<vector<int>> result;
        vector<int> tempResult(nums.size(), 0);
        
        permuteUnique(nums, memory, tempResult, result, 0, nums.size());
        
        return result;
    }
};