/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        if(matrix.size() == 0)
            return result;
        
        int left, right, up, down;
        
        left = up = 0;
        
        down = matrix.size()-1;
        right = matrix[0].size()-1;

        result.resize((down+1) * (right+1));
        
        int index = 0;
        
        while(left <= right && up <= down)
        {
            for(int i = left; i <= right; i++)
                result[index++] = matrix[up][i];
            
            for(int i = up+1; i < down; i++)
                result[index++] = matrix[i][right];
            
            if(down != up)
                for(int i = right; i >= left; i--)
                    result[index++] = matrix[down][i];
            
            if(left != right)
                for(int i = down-1; i > up; i--)
                    result[index++] = matrix[i][left];
            
            left++; right--;
            up++; down--;
        }
        
        return result;
    }
};