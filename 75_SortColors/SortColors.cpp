// SortColors.cpp

/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of the
 * same color are adjacent, with the colors in the order red, white and blue.

 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

 * Note:
 * You are not suppose to use the library's sort function for this problem.

 * click to show follow up.

 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total 
 * number of 0's, then 1's and followed by 2's.

 * Could you come up with an one-pass algorithm using only constant space?
 */

#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int i = 0, j = 0, k = n - 1;

        while (i <= k) {
            switch(A[i]) {
            case 0:
                swap(A[i], A[j]);
                ++i; ++j;
                break;
            case 1:
                ++i;
                break;
            case 2:
                swap(A[i], A[k]);
                --k;
            }
        }
    }
private:
    void swap(int& a, int& b) {
        if (a == b) return;
        a = a^b;
        b = a^b;
        a = a^b;
    }
};

int main(void) {
    Solution so;
    int A[] = {1, 0, 2, 1, 1, 2, 1, 0};
    int len = sizeof(A)/sizeof(*A);
    so.sortColors(A, len);

    for (int i = 0;i < len; ++i)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}