// ClimbingStairs.cpp

/**
 * You are climbing a stair case. It takes n steps to reach to the top.

 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (0 == n) return 0;

        int* ways = new int[n+1];
        memset(ways, 0, (n+1)*sizeof(int));
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;

        int r = findWays(ways, n);
        delete []ways;
        return r;
    }
private:
    int findWays(int* ways, int n) {
        if (0 != ways[n])   return ways[n];
        ways[n] = findWays(ways, n-1) + findWays(ways, n-2);
        return ways[n];
    }
};

int main(void) {
    Solution so;

    cout << so.climbStairs(5) << endl;

    return 0;
}