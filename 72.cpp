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