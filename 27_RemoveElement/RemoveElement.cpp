/**
 * Given an array and a value, remove all instances of that value in place and return the new length.

 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (NULL == A || 0 == n)    return 0;
        int j = n - 1;
        for (int i = 0; i <= j; ++i) {
            if (A[i] == elem) {
                while (A[j] == elem && j > i)   --j;
                if (i == j) { j--; break; }
                A[i] = A[j--];
            }
        }

        return j+1;
    }
};

int main(void) {
    int A[] = {3, 3};
    Solution so;
    cout << so.removeElement(A, 2, 3) << endl;

    return 0;
}