// SetMatrixZeroes.cpp

/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

 * click to show follow up.

 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (0 == row)   return;
        int col = matrix[0].size();
        if (0 == col)   return;

        bool rowFlag = false;
        bool* flag = new bool[col];
        memset(flag, 0, col*sizeof(bool));

        for (int i = 0; i < row; ++i) {
            rowFlag = false;
            for (int j = 0; j < col; ++j) {
                if (0 == matrix[i][j]) {
                    rowFlag = true;
                    flag[j] = true;
                }
            }
            if (true == rowFlag) {
                for (int k = 0; k < col; ++k)
                    matrix[i][k] = 0;
            }
        }

        for (int i = 0; i < col; ++i) {
            if (true == flag[i]) {
                for (int j = 0; j < row; ++j)
                    matrix[j][i] = 0;
            }
        }
    }
};

int main(void) {
    Solution so;
    vector<vector<int>> matrix;
    int A1[] = {1, 2, 3, 0, 5, 6};
    vector<int> v1(A1, A1+6);
    matrix.push_back(v1);
    int A2[] = {0, 2, 3, 4, 5, 0};
    vector<int> v2(A2, A2+6);
    matrix.push_back(v2);
    int A3[] = {1, 2, 3, 4, 5, 6};
    vector<int> v3(A3, A3+6);
    matrix.push_back(v3);

    so.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}