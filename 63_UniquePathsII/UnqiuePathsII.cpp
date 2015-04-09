// UniquePathsII

/**
 * Follow up for "Unique Paths":

 * Now consider if some obstacleGrid are added to the grids. How many unique paths would there be?

 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.

 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.

 * Note: m and n will be at most 100.
*/

// !!!!!! 到达(i,j)的路径等于到达(i-1,j)和(i,j-1)之和来决定。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithobstacleGrid(vector<vector<int> >& obstacleGrid) {
        int row = obstacleGrid.size();
        if (0 == row)   return 0;
        int col = obstacleGrid[0].size();
        if (0==col) return 0;

        if (1 == obstacleGrid[0][0])   return 0;
        obstacleGrid[0][0] = 1;

        for (int i = 1; i < row; ++i) {
            if (0 == obstacleGrid[i-1][0]) obstacleGrid[i][0] = 0;
            else    obstacleGrid[i][0] ^= 1;
        }
        for (int j = 1; j < col; ++j) {
            if (0 == obstacleGrid[0][j-1]) obstacleGrid[0][j] = 0;
            else    obstacleGrid[0][j] ^= 1;
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (1 == obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = 0;
                }
                else
                    obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
            }
        }

        return obstacleGrid[row-1][col-1];
    }
};

int main(void) {
    Solution so;
    vector<int> vr(3, 0);
    vector<vector<int> > v(3, vr);

    v[1][1] = 1;

    cout << so.uniquePathsWithobstacleGrid(v) << endl;

    return 0;
}