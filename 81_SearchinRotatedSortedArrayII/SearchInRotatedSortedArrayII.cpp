// SearchInRotatedSortedArrayII.cpp

/**
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?

 * Would this affect the run-time complexity? How and why?

 * Write a function to determine if a given target is in the array.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1;

        while (l <= r) {
            int m = l + ((r-l)>>1);
            if (A[m] == target)   return true;
            if (A[l] < A[m]) {  // ◊Û±ﬂ“—≈≈∫√–Ú
                if (target>=A[l] && target<=A[m]) r = m - 1;
                else    l = m + 1;
            }
            else if (A[l] > A[m]) { // ”“±ﬂ“—≈≈∫√–Ú
                if (target<=A[r] && target>=A[m])   l = m + 1;
                else    r = m - 1;
            }
            else    ++l;
        }

        return false;
    }
};

int main(void) {
    Solution so;

    int A[] = {4, 5, 6, 1, 2, 3};

    cout << so.search(A, 5, 1) << endl;
    cout << so.search(A, 5, 6) << endl;

    return 0;
}