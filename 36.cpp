/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    bool checkAllRows(vector<vector<char>>& board)
    {
        bool count[10];
        
        for(int i = 0; i < 9; i++)
        {
            memset(count, false, sizeof(count));
            
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(count[board[i][j]-'0'])
                        return false;
                    else
                        count[board[i][j]-'0'] = true;
                }
            }
        }
        
        return true;
    }
    
    bool checkAllColumns(vector<vector<char>>& board)
    {
        bool count[10];
        
        for(int i = 0; i < 9; i++)
        {
            memset(count, false, sizeof(count));
            
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    if(count[board[j][i]-'0'])
                        return false;
                    else
                        count[board[j][i]-'0'] = true;
                }
            }
        }
        
        return true;
    }
    
    bool checkAllSquares(vector<vector<char>>& board)
    {
        bool count[10];
        int row, col;
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                memset(count, false, sizeof(count));
                
                for(int k = 0; k < 3; k++)
                {
                    for(int l = 0; l < 3; l++)
                    {
                        row = i*3+k;
                        col = j*3+l;
                        
                        if(board[row][col] != '.')
                        {
                            if(count[board[row][col]-'0'])
                                return false;
                            else
                                count[board[row][col]-'0'] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(!checkAllRows(board))
            return false;

        if(!checkAllColumns(board))
            return false;
        
        if(!checkAllSquares(board))
            return false;

        return true;
    }
};