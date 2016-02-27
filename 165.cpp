/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    void splitByDot(string& version, vector<int>& ver)
    {
        int curr = 0;
        
        for(int i = 0; i < version.length(); i++)
        {
            if(version[i] == '.')
            {
                ver.push_back(curr);
                curr = 0;
            }
            else
                curr = curr*10 + version[i] - '0';
        }
        
        ver.push_back(curr);
    }
    
    void trimRightZeroes(vector<int>& ver)
    {
        while(!ver[ver.size()-1])
            ver.pop_back();
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1;
        vector<int> ver2;
        
        splitByDot(version1, ver1);
        splitByDot(version2, ver2);
        
        trimRightZeroes(ver1);
        trimRightZeroes(ver2);

        int i;
        
        for(i = 0; i < ver1.size() && i < ver2.size(); i++)
        {
            if(ver1[i] > ver2[i])
                return 1;
            else if(ver1[i] < ver2[i])
                return -1;
        }
        
        if(i < ver1.size())
            return 1;
        
        if(i < ver2.size())
            return -1;
            
        return 0;
    }
};