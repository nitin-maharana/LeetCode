/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
    static bool compare(Interval a, Interval b)
    {
        return (a.start < b.start);
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i-1].end > intervals[i].start)
                return false;

        return true;
    }
};