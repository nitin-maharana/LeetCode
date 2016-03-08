/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    vector<vector<int>> result;
    
    void combine(int i, int n, int k, vector<int>& tempRes)
    {
        if(!k)
        {
            result.push_back(tempRes);
            return;
        }
            
        for(int x = i; x <= n-k+1; x++)
        {
            tempRes.push_back(x);
            combine(x+1, n, k-1, tempRes);
            tempRes.pop_back();
        }
        
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if(!n)
            return result;
        
        vector<int> tempResult;
        tempResult.reserve(k);
        
        combine(1, n, k, tempResult);
        
        return result;
    }
};