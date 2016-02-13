/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    map<pair<int, int>, bool> memory;
    map<pair<int, int>, bool>::iterator it;
    bool result;
    
public:
    bool isMatchUtil(string &s, string &p, int i, int j)
    {
        if(i == s.length() && j == p.length())
            return true;

        if(i < s.length() && j >= p.length())
            return false;

        it = memory.find(make_pair(i,j));

        if(it != memory.end())
            return it->second;

        if(i < s.length())
        {
            if(j+1 < p.length())
            {
                if(p[j+1] == '*')
                {
                    if(p[j] == '.' || p[j] == s[i])
                    {
                        result = (isMatchUtil(s, p, i, j+2) || isMatchUtil(s, p, i+1, j));
                        memory.insert(make_pair(make_pair(i,j), result));
                        return result;
                    }
                    else
                    {
                        result = isMatchUtil(s, p, i, j+2);
                        memory.insert(make_pair(make_pair(i,j), result));
                        return result;
                    }
                }
            }

            if(p[j] == '.' || p[j] == s[i])
            {
                result = isMatchUtil(s, p, i+1, j+1);
                memory.insert(make_pair(make_pair(i,j), result));
                return result;
            }
            else
                return false;
        }
        else
        {
            if(j+1 < p.length())
                if(p[j+1] == '*')
                {
                    result = isMatchUtil(s, p, i, j+2);
                    memory.insert(make_pair(make_pair(i,j), result));
                    return result;
                }

            return false;
        }
    }

    bool isMatch(string s, string p) {
        return isMatchUtil(s, p, 0, 0);
    }
};