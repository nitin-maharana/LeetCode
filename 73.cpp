/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(!matrix.size())
            return;
        
        int m, n;
        bool firstRow, firstColumn;
        
        m = matrix.size();
        n = matrix[0].size();
        firstRow = firstColumn = false;
        
        for(int i = 0; i < n; i++)
        {
            if(matrix[0][i] == 0)
            {
                firstRow = true;
                break;
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(matrix[i][0] == 0)
            {
                firstColumn = true;
                break;
            }
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++)
        {
            if(!matrix[i][0])
            {
                for(int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            if(!matrix[0][i])
            {
                for(int j = 1; j < m; j++)
                    matrix[j][i] = 0;
            }
        }
        
        if(firstRow)
            for(int i = 0; i < n; i++)
                matrix[0][i] = 0;
        
        if(firstColumn)
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        
        return;
    }
};