/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> memory1;
        unordered_map<string,char> memory2;
        string word;
        int index = 0;
        
        for(int i = 0; i < pattern.length(); i++)
        {
            word = "";
            
            while(index < str.length())
            {
                if(str[index] != ' ')
                    break;
                index++;
            }
            
            if(index >= str.length())
                return false;
                
            while(index < str.length())
            {
                if(str[index] == ' ')
                    break;
                    
                word += str[index++];
            }
            
            if(memory1.find(pattern[i]) != memory1.end())
            {
                if(memory1[pattern[i]] != word)
                    return false;
            }
            else if(memory2.find(word) != memory2.end())
                    return false;
            else
            {
                memory1[pattern[i]] = word;
                memory2[word] = pattern[i];
            }
        }

        while(index < str.length())
            if(str[index++] != ' ')
                return false;
        
        return true;
    }
};