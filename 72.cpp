/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Recursive Solution.
class Solution {
    int minDistance(string& word1, string& word2, vector<vector<int>>& memory, int i, int j)
    {
        if(i == 0)
            return j;
        
        if(j == 0)
            return i;
        
        if(memory[i-1][j-1] != -1)
            return memory[i-1][j-1];
        
        if(word1[i-1] == word2[j-1])
            return minDistance(word1, word2, memory, i-1, j-1);
        
        memory[i-1][j-1] = 1 + min(min(minDistance(word1, word2, memory, i, j-1), minDistance(word1, word2, memory, i-1, j)), minDistance(word1, word2, memory, i-1, j-1));
        
        return memory[i-1][j-1];
    }
public:
    int minDistance(string word1, string word2) {
        int m, n;
        
        m = word1.length();
        n = word2.length();
        
        vector<vector<int>> memory(m, vector<int>(n, -1));
        
        return minDistance(word1, word2, memory, m, n);
    }
};

//Iterative Solution.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m, n;
        
        m = word1.length();
        n = word2.length();
        
        vector<vector<int>> memory(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i <= m; i++)
            memory[i][0] = i;
        
        for(int j = 0; j <= n; j++)
            memory[0][j] = j;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i-1] == word2[j-1])
                    memory[i][j] = memory[i-1][j-1];
                else
                    memory[i][j] = 1 + min(memory[i-1][j-1], min(memory[i-1][j], memory[i][j-1]));
            }
        }
        
        return memory[m][n];
    }
};