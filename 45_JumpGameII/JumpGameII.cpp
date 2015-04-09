// JumpGameII.cpp

/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

 * Each element in the array represents your maximum jump length at that position.

 * Your goal is to reach the last index in the minimum number of jumps.

 * For example:
 * Given array A = [2,3,1,1,4]

 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to 
 * the last index.)
 */

/**
 * 思路来自：https://leetcode.com/discuss/10588/o-n-bfs-solution
 * I try to change this problem to a BFS problem, where nodes in level i are all the nodes 
 * that can be reached in i-1th jump. for example. 2 3 1 1 4 , is 2|| 3 1|| 1 4 ||
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int max=0, curmax=0, level=0;
        int i = 0;
        if (n < 2)  return 0;
        while (curmax-i+1 > 0) {    // 最大能到达的点与当前点之间的点数
            ++level;
            for (;i <= curmax; ++i) {
                max = i+A[i] > max ? i+A[i] : max;
                if (max >= n-1) return level;
            }
            curmax = max;
        }
        return -1;
    }
};

int main(void) {
    Solution so;
    int A[] = {2, 3, 1, 1, 4};

    cout << so.jump(A, sizeof(A)/sizeof(*A)) << endl;

    return 0;
}