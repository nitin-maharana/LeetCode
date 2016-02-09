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