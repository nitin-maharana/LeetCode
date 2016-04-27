/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    string reverseString(string s) {
        int l, r;

        l = 0;
        r = s.length()-1;

        while(l < r)
            swap(s[l++], s[r--]);

        return s;
    }
};