/**
 * Given an unsorted integer array, find the first missing positive integer.

 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.

 * Your algorithm should run in O(n) time and uses constant space.
 */

// 解题思想!!!!!!!!!!!


#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i) {
            // A[A[i]-1]!=A[i]可以防止当A[A[i]-1]==A[i](eg.[1,1])时产生的无限循环
            // 同时确保了A[i]-1!=i
            while (A[i]>0 && A[i]<=n && /*A[i]-1!=i && */A[A[i]-1]!=A[i])  swap(A[i], A[A[i]-1]);
        }

        int j = 0;
        for (; j < n; ++j) {
            if (A[j]-1 != j)    break;
        }

        return j+1;
    }
private:
    void swap(int& a, int& b) {
        a = a^b;
        b = a^b;
        a = a^b;
    }
};

int main(void) {
    Solution so;
    int A1[] = {1, 2, 0};
    int A2[] = {3, 4, -1, 1};
    int A3[] = {1, 1};
    int A4[] = {-1, 4, 2, 1, 9, 10};

    cout << so.firstMissingPositive(A1, sizeof(A1)/sizeof(*A1)) << endl;
    cout << so.firstMissingPositive(A2, sizeof(A2)/sizeof(*A2)) << endl;
    cout << so.firstMissingPositive(A3, sizeof(A3)/sizeof(*A3)) << endl;
    cout << so.firstMissingPositive(A4, sizeof(A4)/sizeof(*A4)) << endl;

    return 0;
}