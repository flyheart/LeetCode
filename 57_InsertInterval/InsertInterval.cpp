// InsertInterval.cpp

/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

 * You may assume that the intervals were initially sorted according to their start times.

 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

#include <iostream>
#include <vector>
using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        int size = intervals.size();
        if (0 == size) {  
            ret.push_back(newInterval);
            return ret;
        }
        int m1 = search(intervals, 0, size-1, newInterval.start);
        int m2 = search(intervals, 0, size-1, newInterval.end);

        for (int i = 0; i < m1; ++i) {
            ret.push_back(intervals[i]);
        }
        if (m1 >= size) {
            ret.push_back(newInterval);
            return ret;
        }

        Interval interval;
        if (newInterval.start < intervals[m1].start) {
            interval.start = newInterval.start;
        }
        else {
            interval.start = intervals[m1].start;
        }
        if (m2 == size) {
            interval.end = newInterval.end;
            ret.push_back(interval);
            return ret;
        }
        else if (newInterval.end < intervals[m2].start){
            interval.end = newInterval.end;
            ret.push_back(interval);
            ret.push_back(intervals[m2]);
        }
        else {
            interval.end = intervals[m2].end;
            ret.push_back(interval);
        }
        for (int j=m2+1; j < size; ++j) {
            ret.push_back(intervals[j]);
        }

        return ret;

    }
private:
    int search(const vector<Interval>& intervals, int start, int end, int target) {
        if (start > end) return start;
        int mid = (start + end) / 2;
        if (target>=intervals[mid].start && target<=intervals[mid].end)  return mid;
        else if (target > intervals[mid].end) {
            return search(intervals, mid+1, end, target);
        }
        else {
            return search(intervals, start, mid-1, target);
        }
    }
};

int main(void) {
    Solution so;
    vector<Interval> input;
    Interval i1(1, 5);
    input.push_back(i1);
    Interval t(2, 3);

    vector<Interval> output = so.insert(input, t);

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i].start << ", " << output[i].end << endl;
    }

    return 0;
}