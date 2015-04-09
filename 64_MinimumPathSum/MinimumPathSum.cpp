// MinimumPathSum.cpp

/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom 
 * right which minimizes the sum of all numbers along its path.

 * Note: You can only move either down or right at any point in time.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int row = grid.size();
        if (0 == row)   return 0;
        int col = grid[0].size();
        if (0 == col)   return 0;

        for (int i = 1; i < row; ++i) {
            grid[i][0] += grid[i-1][0];
        }
        for (int j = 1; j < col; ++j) {
            grid[0][j] += grid[0][j-1];
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (grid[i-1][j] <= grid[i][j-1])
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += grid[i][j-1];
            }
        }

        return grid[row-1][col-1];
    }
};

int main(void) {
    Solution so;
    vector<int> vr(3, 0);
    vector<vector<int> > v(4, vr);

    v[1][1] = 1;

    cout << so.minPathSum(v) << endl;

    return 0;
}