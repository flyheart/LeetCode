// RemoveDuplicationfromSortedArrayII.cpp

/**
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?

 * For example,
 * Given sorted array A = [1,1,1,2,2,3],

 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int cnt = 1;
        int index = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] == A[i-1]) {
                ++cnt;
                if (cnt <= 2)    { A[index++] = A[i]; }
            }
            else {
                A[index++] = A[i];
                cnt=1;
            }
        }

        return index;
    }
};

int main(void) {
    Solution so;
    int A[] = {1, 1, 1, 2, 2, 3, 3, 3};
    int len = so.removeDuplicates(A, sizeof(A)/sizeof(*A));
    
    for (int i = 0; i < len; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}