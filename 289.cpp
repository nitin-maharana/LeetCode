/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    void checkLiveOrDead(vector<vector<int>>& board, int m, int n)
    {
        int countOnes;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                countOnes = 0;
                
                for(int k = max(i-1, 0); k <= min(i+1, m-1); k++)
                    for(int l = max(j-1, 0); l <= min(j+1, n-1); l++)
                        countOnes += (board[k][l] & 1);
                
                countOnes -= (board[i][j] & 1);
                
                if(countOnes < 2 || countOnes > 3 || (!(board[i][j] & 1) && countOnes == 2))
                    board[i][j] &= 1;
                else
                    board[i][j] |= 2;
            }
        }
    }
    
    void makeChanges(vector<vector<int>>& board, int m, int n)
    {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m, n;
        
        m = board.size();
        
        if(!m)
            return;
        
        n = board[0].size();
        
        checkLiveOrDead(board, m, n);
        
        makeChanges(board, m, n);
    }
};