/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//O(M+N)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n;
        
        m = matrix.size();
        
        if(!m)
            return false;
        
        n = matrix[0].size();
        
        int x, y;
        
        x = 0; y = n-1;
        
        while(x < m && y >= 0)
        {
            if(matrix[x][y] == target)
                return true;
            
            if(target > matrix[x][y])
                x++;
            else
                y--;
        }
        
        return false;
    }
};

//O(logM + logN)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n;
        
        m = matrix.size();
        
        if(!m)
            return false;
        
        n = matrix[0].size();
        
        int x, y, l, r, mid;
        
        x = 0; y = n-1;
        
        while(x < m && y >= 0)
        {
            if(matrix[x][y] == target)
                return true;
            
            if(target < matrix[x][y])
            {
                l = 0;
                r = y;
                
                while(l <= r)
                {
                    mid = l + ((r-l) / 2);
                    
                    if(target == matrix[x][mid])
                        return true;
                    
                    if(target < matrix[x][mid])
                        y = r = mid-1;
                    else
                        y = l = mid+1;
                }
            }
            else
            {
                l = 0;
                r = x;
                
                while(l <= r)
                {
                    mid = l + ((r-l) / 2);
                    
                    if(target == matrix[mid][y])
                        return true;
                    
                    if(target < matrix[mid][y])
                        x = r = mid-1;
                    else
                        x = l = mid+1;
                }
            }
        }
        
        return false;
    }
};