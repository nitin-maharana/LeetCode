/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() == 0)
            return 0;

        int memory[words.size()] = {0};

        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words[i].size(); j++)
                memory[i] |= (1 << (words[i][j]-'a'));

        int maxprod = 0;

        for(int i = 0; i < words.size() - 1; i++)
            for(int j = i+1; j < words.size(); j++)
                if((memory[i] & memory[j]) == 0)
                    maxprod = max(maxprod, (int)(words[i].size()*words[j].size()));

        return maxprod;
    }
};