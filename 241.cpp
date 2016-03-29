/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    unordered_map<string, vector<int>> memory;
public:
    vector<int> diffWaysToCompute(string input) {

        if(memory.find(input) != memory.end())
            return memory[input];

        vector<int> result;

        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == '*' || input[i] == '+' || input[i] == '-')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));

                for(int l : left)
                {
                    for(int r : right)
                    {
                        switch(input[i])
                        {
                            case '*':   result.emplace_back(l*r);
                                        break;
                            case '+':   result.emplace_back(l+r);
                                        break;
                            case '-':   result.emplace_back(l-r);
                                        break;
                        }
                    }
                }
            }
        }
        
        if(result.empty())
            result.emplace_back(stoi(input));
        
        memory.insert(make_pair(input, result));
        
        return result;
    }
};