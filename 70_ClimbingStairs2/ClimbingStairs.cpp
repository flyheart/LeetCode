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
        int* ways = new int[n+1];
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;

        for (int i = 3; i <= n; ++i) {
            ways[i] = ways[i-1] + ways[i-2];
        }

        int r = ways[n];
        delete []ways;

        return r;
    }
};

int main(void) {
    Solution so;

    cout << so.climbStairs(5) << endl;

    return 0;
}