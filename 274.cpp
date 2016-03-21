/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Time: O(n), Space: O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        
        int memory[len+1];
        
        memset(memory, 0, sizeof memory);
        
        for(int i = 0; i < len; i++)
            memory[min(citations[i], len)]++;
        
        for(int i = len; i > 0; i--)
        {
            if(memory[i] >= i)
                return i;
            
            memory[i-1] += memory[i];
        }
        
        return 0;
    }
};

//Time: O(nLogn), Space: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int len = citations.size();
        
        for(int i = 0; i < len; i++)
            if(citations[i] >= len-i)
                return len-i;
        
        return 0;
    }
};