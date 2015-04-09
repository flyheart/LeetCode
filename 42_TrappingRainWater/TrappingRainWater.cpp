/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. // 数组中各元素表示高度 (https://leetcode.com/problems/trapping-rain-water/)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        return trap_water(A, 0, n);
    }
private:
    int trap_water(int A[], int start, int n) {
        while (start<n && 0==A[start])  ++start;
        if (n == start) return 0;
        int area = 0;
        int highest = start + 1;    
        int i = start+1;
        while (i<n && A[i]<A[start]) {
            highest = A[i] > A[highest] ? i : highest;
            ++i;
        }
        /*
        if (i == n) {
            area += calc_area(A, start, highest);
            area += trap_water(A, highest, n);
        }
        else {
            area += calc_area(A, start, i);
            area += trap_water(A, i, n);
        }
        */
        // 与上面注释掉的代码功能相同
        if (i != n) highest = i;
        area += calc_area(A, start, highest);
        area += trap_water(A, highest, n);

        return area;
    }
    int calc_area(int A[], int start, int end) {
        int min = A[start]<=A[end] ? A[start] : A[end];
        int area = (end-start-1) * min;
        for (int i=start+1; i < end; ++i)
            area -= A[i];

        return area;
    }
};

int main(void) {
    Solution so;
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << so.trap(A, sizeof(A)/sizeof(*A)) << endl;

    return 0;
}