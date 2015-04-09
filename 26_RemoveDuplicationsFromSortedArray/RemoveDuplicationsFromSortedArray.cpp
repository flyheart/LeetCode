/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once 
 * and return the new length.

 * Do not allocate extra space for another array, you must do this in place with constant memory.

 * For example,
 * Given input array A = [1,1,2],

 * Your function should return length = 2, and A is now [1,2].
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (0 == n) return 0;   // !!!!!!!!!!!GG
        int index = 1;  // 指向待填充非重复元素的其实位置
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[i-1]) {
                A[index++] = A[i];
            }
        }

        return index;
    }
};

int main(void) {
    Solution so;
    int A[] = {1, 1, 2, 3, 4};
    cout << so.removeDuplicates(A, 5) << endl;

    return 0;
}