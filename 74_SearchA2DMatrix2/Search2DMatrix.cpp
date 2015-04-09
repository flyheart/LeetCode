// Search2DMatrix.cpp

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the
 * following properties:

 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,

 * Consider the following matrix:

 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if (0 == row)   return false;
        int col = matrix[0].size();
        if (0 == col)   return false;
        int start = 0, end = row*col-1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == matrix[mid/col][mid%col]) return true;
            else if (target > matrix[mid/col][mid%col]) start = mid + 1;
            else    end = mid - 1;
        }

        return false;
    }
};

int main(void) {
    Solution so;
    vector<vector<int>> matrix;
    int A1[] = {1, 2, 3, 4, 5, 6};
    vector<int> v1(A1, A1+6);
    matrix.push_back(v1);
    int A2[] = {10, 12, 13, 14, 15, 16};
    vector<int> v2(A2, A2+6);
    matrix.push_back(v2);
    int A3[] = {21, 22, 23, 24, 25, 26};
    vector<int> v3(A3, A3+6);
    matrix.push_back(v3);

    cout << so.searchMatrix(matrix, 10) << endl;
    cout << so.searchMatrix(matrix, 0) << endl;
    cout << so.searchMatrix(matrix, 6) << endl;
    cout << so.searchMatrix(matrix, 13) << endl;
    cout << so.searchMatrix(matrix, 27) << endl;

    return 0;
}