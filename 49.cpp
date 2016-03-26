/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        if(strs.size() == 0)
            return result;
        
        int index = 0;
        unordered_map<string, int> memory;
        string temp;
        
        for(string s: strs)
        {
            temp = s;
            sort(temp.begin(), temp.end());
            
            if(memory.find(temp) == memory.end())
            {
                memory.insert(make_pair(temp, index++));
                vector<string> tempRes;
                tempRes.push_back(s);
                result.push_back(tempRes);
            }
            else
                result[memory[temp]].push_back(s);
        }
        
        for(int i = 0; i < result.size(); i++)
            sort(result[i].begin(), result[i].end());
        
        return result;
    }
};