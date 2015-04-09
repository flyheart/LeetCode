// MergeIntervals.cpp

/**
 * Given a collection of intervals, merge all overlapping intervals.

 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), compare);

        int size = intervals.size();
        if (0 == size)  return ret;
        Interval interval = intervals[0];
        for (int i = 1; i < size; ++i) {
            if (interval.end >= intervals[i].start) {
                interval.end = intervals[i].end > interval.end ? intervals[i].end : interval.end;
            }
            else {
                ret.push_back(interval);
                interval = intervals[i];
            }
        }
        ret.push_back(interval);
        return ret;
    }
private:
    static bool compare(Interval v1, Interval v2) { return v1.start <= v2.start; }
    int max(int a, int b) { return a>=b?a:b; }
};

int main() {

    return 0;
}