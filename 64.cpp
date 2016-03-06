/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//O(M*N) Time & O(M+N) Space Complexity. No change in original matrix.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        
        int m, n;
        
        m = grid.size();
        n = grid[0].size();
        
        int row[n], column[m];
        
        row[n-1] = grid[m-1][n-1];
        column[m-1] = row[n-1];
        
        for(int i = n-2; i >= 0; i--)
            row[i] = grid[m-1][i] + row[i+1];
        
        for(int i = m-2; i >= 0; i--)
            column[i] = grid[i][n-1] + column[i+1];
        
        for(int i = m-2; i >= 0; i--)
        {
            for(int j = n-2; j >= 0; j--)
            {
                row[j] = grid[i][j] + min(row[j], column[i]);
                column[i] = row[j];
            }
        }

        return row[0];
    }
};

//O(M*N) Time & O(1) Space Complexity. Change in original matrix.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        
        int m, n;
        
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 1; i < m; i++)
            grid[i][0] += grid[i-1][0];
        
        for(int i = 1; i < n; i++)
            grid[0][i] += grid[0][i-1];
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);

        return grid[m-1][n-1];
    }
};