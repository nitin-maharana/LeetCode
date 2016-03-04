/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Iterative Solution.
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m || !n)
            return 0;
            
        int memory[m][n];
        
        memset(memory, -1, sizeof memory);
        
        for(int i = 0; i < m; i++)
            memory[i][n-1] = 1;
        for(int i = 0; i < n; i++)
            memory[m-1][i] = 1;
        
        for(int i = m-2; i >= 0; i--)
            for(int j = n-2; j >= 0; j--)
                memory[i][j] = memory[i][j+1] + memory[i+1][j];

        return memory[0][0];
    }
};

//Recursive Solution with MAP.
class Solution {
    map<pair<int,int>, int> memory;
    map<pair<int,int>, int>::iterator it;
    
    int uniquePaths(int i, int j, int m, int n)
    {
        if(i == m ||  j == n)
            return 1;
        
        it = memory.find(make_pair(i,j));
        
        if(it != memory.end())
            return it->second;
        
        int result;
        
        result = uniquePaths(i, j+1, m, n) + uniquePaths(i+1, j, m, n);
        memory.insert(make_pair(make_pair(i,j), result));
        
        return result;
    }
public:
    int uniquePaths(int m, int n) {
        return uniquePaths(1, 1, m, n);
    }
};