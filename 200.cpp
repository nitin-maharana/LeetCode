/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    void destroyIsland(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';
        
        if(i-1 >= 0 && grid[i-1][j] == '1')
            destroyIsland(grid, i-1, j);
        
        if(i+1 < grid.size() && grid[i+1][j] == '1')
            destroyIsland(grid, i+1, j);
        
        if(j-1 >= 0 && grid[i][j-1] == '1')
            destroyIsland(grid, i, j-1);
        
        if(j+1 < grid[i].size() && grid[i][j+1] == '1')
            destroyIsland(grid, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    result++;
                    destroyIsland(grid, i, j);
                }
            }
        }
        
        return result;
    }
};