/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        
        if(!n)
            return result;
        
        int count = 1;
        int level = ceil(n/2.0f);
        int r;
        
        for(int l = 0; l < level; l++)
        {
            r = n-1-l;
            
            if(l == r)
            {
                result[l][r] = count;
                break;
            }
            
            for(int i = l; i <= r; i++)
                result[l][i] = count++;
            
            for(int i = l+1; i < r; i++)
                result[i][r] = count++;
            
            for(int i = r; i >= l; i--)
                result[r][i] = count++;
            
            for(int i = r-1; i > l; i--)
                result[i][l] = count++;
        }
        
        return result;
    }
};