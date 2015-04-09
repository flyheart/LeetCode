// UnqiuePaths.cpp

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 * The robot can only move either down or right at any point in time. The robot is trying to reach 
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 * How many possible unique paths are there?
 */

// º∆À„C_(m+n-2) (m-1) || C_(m+n-2) (n-1)

#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n > m)  swap(m, n);
        --n;
        --m;

        return combination(m+n, n);
    }
private:
    int combination(int m, int n) {
        long long multi = 1;
        for (int i = 1; i <= n; ++i) {
            multi = multi*m--/i;
        }

        return multi;
    }
};

int main(void) {
    Solution so;

    cout << so.uniquePaths(3,3) << endl;

    return 0;
}