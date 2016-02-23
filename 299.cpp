/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int len;
public:
    string getHint(string secret, string guess) {
        len = secret.length();
        
        int secretCowCount[10] = {0};
        int guessCowCount[10] = {0};
        int bulls = 0;
        int cows = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(secret[i] == guess[i])
                bulls++;
            else
            {
                secretCowCount[secret[i]-'0']++;
                guessCowCount[guess[i]-'0']++;
            }
        }
        
        for(int i = 0; i < 10; i++)
            cows += min(secretCowCount[i], guessCowCount[i]);
            
        stringstream convert;
        string result = "";
        
        convert << bulls << "A" << cows << "B";
        
        result = convert.str();
        
        return result;
    }
};