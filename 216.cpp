/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    vector<vector<int>> result;
    
    void combinationSum3(int num, int k, int n, vector<int>& tempRes, int sum)
    {
        if(k == 0 && sum == n)
        {
            result.push_back(tempRes);
            return;
        }
        
        for(int i = num; i < 10; i++)
        {
            if(i + sum <= n && k)
            {
                tempRes.push_back(i);
                combinationSum3(i+1, k-1, n, tempRes, sum+i);
                tempRes.pop_back();
            }
            else
                return;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(!k)
            return result;
        
        vector<int> tempRes;
        tempRes.reserve(k);
        
        combinationSum3(1, k, n, tempRes, 0);
        
        return result;
    }
};