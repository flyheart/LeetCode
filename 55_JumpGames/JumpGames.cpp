// JumpGames.cpp

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

 * Each element in the array represents your maximum jump length at that position.

 * Determine if you are able to reach the last index.

 * For example:
 * A = [2,3,1,1,4], return true.

 * A = [3,2,1,0,4], return false.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump2(int A[], int n) {
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + A[i], reach);
        return i == n;
    }

    bool canJump(int A[], int n) {
        if (0 == n) return true;
        int max = 0;
        int index = 0;
        while (index <= max) {
            int sum = 0;
            int submax = 0;
            for (int i = index; i <= max; ++i) {
                sum = i + A[i];
                submax = submax >= sum ? submax : sum;
                if (submax >= n-1)  return true;
            }
            index = max + 1;
            max = max >= submax ? max : submax;
        }

        return false;
    }

};

int main(void) {
    Solution so;
    int A[] = {2, 3, 1, 1, 4};
    int A2[] = {3, 2, 1, 0, 4};

    cout << so.canJump(A, sizeof(A)/sizeof(*A)) << endl;
    cout << so.canJump(A2, sizeof(A2)/sizeof(*A2)) << endl;

    return 0;
}