// SpiralMatrixII.cpp

/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

 * For example,
 * Given n = 3,

 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> v(n, 0);
        vector<vector<int> > ret(n, v);
        index = 0;
        __generateMatrix(ret, 0, n-1, 0, n-1);

        return ret;
    }
private:
    int index;
    void __generateMatrix(vector<vector<int> >& ret, int lcol, int rcol, int top, int bottom) {
        while (true) {
            for (int i = lcol; i <= rcol; ++i) {
                ret[top][i] = ++index;
            }
            if (++top > bottom) break;
            for (int j = top; j <= bottom; ++j) {
                ret[j][rcol] = ++index;
            }
            if (--rcol < lcol)  break;
            for (int k = rcol; k >= lcol; --k) {
                ret[bottom][k] = ++index;
            }
            if (--bottom < top) break;
            for (int m = bottom; m >= top; --m) {
                ret[m][lcol] = ++index;
            }
            if (++lcol > rcol)  break;
        }
    }
};

int main(void) {
    Solution so;

    vector<vector<int>> ret = so.generateMatrix(5);

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}