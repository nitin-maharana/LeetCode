class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
            
        int x1, x2, mid, first, last;
        
        x1 = 0;
        x2 = matrix.size()-1;
        
        while(x1 <= x2)
        {
            if(x1 == x2)
                break;

            mid = x1 + ((x2 - x1) / 2);
            first = matrix[mid][0];
            last = matrix[mid][matrix[mid].size()-1];
            
            if(target >= first && target <= last)
            {
                x1 = x2 = mid;
                break;
            }
            
            if(target > last)
                x1 = mid+1;
            else
                x2 = mid-1;
        }
        
        if(x1 > x2)
            return false;
        
        int y1, y2, midElem;
        
        y1 = 0;
        y2 = matrix[x1].size()-1;
        
        while(y1 <= y2)
        {
            mid = y1 + ((y2 - y1) / 2);
            midElem = matrix[x1][mid];
            
            if(target == midElem)
                return true;
            
            if(target > midElem)
                y1 = mid+1;
            else
                y2 = mid-1;
        }
        
        return false;
    }
};
