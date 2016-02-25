/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int haystackLen, needleLen;
    
    void findPrefixArray(string& pattern, int *prefix)
    {
        int lastPrefixLen = 0;
        prefix[0] = 0;
        int i = 1;
        
        while(i < needleLen)
        {
            if(pattern[i] == pattern[lastPrefixLen])
            {
                lastPrefixLen++;
                prefix[i] = lastPrefixLen;
                i++;
            }
            else
            {
                if(lastPrefixLen)
                    lastPrefixLen = prefix[lastPrefixLen-1];
                else
                {
                    prefix[i] = 0;
                    i++;
                }
            }
        }
    }
    
public:
    int strStr(string haystack, string needle) {
        haystackLen = haystack.length();
        needleLen = needle.length();
        
        if(!needleLen)
            return 0;
        
        int *prefixArray = new int[needleLen];
        
        findPrefixArray(needle, prefixArray);
        
        int i = 0, j = 0;
        
        while(i < haystackLen)
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            
            if(j == needleLen)
                return (i-j);
            else if((i < haystackLen) && (haystack[i] != needle[j]))
            {
                if(j != 0)
                    j = prefixArray[j-1];
                else
                    i++;
            }
        }
        
        return -1;
    }
};

class Solution1 {
    int haystackLen, needleLen;
    
    void findPrefixArray(string& needle, int *prefix)
    {
        prefix[0] = -1;
        
        int i = 0, j = -1;
        
        while(i < needleLen-1)
        {
            if(j == -1 || needle[i] == needle[j])
            {
                i++; j++;
                prefix[i] = j;
            }
            else
                j = prefix[j];
        }
    }
    
public:
    int strStr(string haystack, string needle)
    {
        haystackLen = haystack.length();
        needleLen = needle.length();
        
        int *prev = new int[needleLen];
        
        findPrefixArray(needle, prev);
        
        int i = 0, j = 0;
        
        while(i < haystackLen && j < needleLen)
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
                j = prev[j];
        }
        
        if(j == needleLen)
            return (i - j);
        else
            return -1;
      }
};