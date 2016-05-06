/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Without using HashMap. O(nlogn) Solution.

struct number{
    int element;
    int index;
};

bool ascending(struct number n1, struct number n2)
{
    return (n1.element < n2.element);
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        struct number input[nums.size()];

        for(int i = 0; i < nums.size(); i++)
        {
            input[i].element = nums[i];
            input[i].index = i;
        }

        sort(input, input+nums.size(), ascending);

        int l, r;

        l = 0;
        r = nums.size()-1;

        while(1)
        {
            if(target == (input[l].element+input[r].element))
                break;

            if(target < (input[l].element+input[r].element))
                r--;
            else
                l++;
        }

        vector<int> result(2);

        l = input[l].index + 1;
        r = input[r].index + 1;

        if(l < r)
        {
            result[0] = l;
            result[1] = r;
        }
        else
        {
            result[0] = r;
            result[1] = l;
        }

        return result;
    }
};

//Without using HashMap. O(nlogn) Solution. According to latest modification of question.
class Solution {
    static bool ascending(pair<int, int>& n1, pair<int, int>& n2)
    {
        return (n1.first < n2.first);
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> memory;
        
        for(int i = 0; i < nums.size(); i++)
            memory.push_back(make_pair(nums[i], i));

        sort(memory.begin(), memory.end(), ascending);
        
        int l, r;
        vector<int> result;
        
        l = 0;
        r = nums.size()-1;
        
        while(l < r)
        {
            if((memory[l].first + memory[r].first) == target)
            {
                result.push_back(memory[l].second);
                result.push_back(memory[r].second);
                return result;
            }
            
            if((memory[l].first + memory[r].first) > target)
                r--;
            else
                l++;
        }
        
        memory.clear();
        
        return result;
    }
};

//Using HashMap. Time : O(n), Space : O(n).
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> memory;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(memory.find(target-nums[i]) != memory.end())
            {
                result.push_back(memory[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            
            memory[nums[i]] = i;
        }
        
        memory.clear();
        return result;
    }
};