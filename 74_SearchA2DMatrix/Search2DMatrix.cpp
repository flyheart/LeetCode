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
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        if (0 == row)   return false;
        int col = matrix[0].size();
        if (0 == col)   return false;

        int pos = binaryRowSearch(matrix, target, 0, row-1);
        return binaryElementSearch(matrix, target, pos, 0, col-1);
    }
private:
    int binaryRowSearch(vector<vector<int> >& matrix, int target, int start, int end) {
        int guard = end;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (mid == guard)   return mid;
            else if (target>=matrix[mid][0] && target<matrix[mid+1][0])   return mid;
            else if (target < matrix[mid][0])   end = mid - 1;
            else    start = mid+1;
        }

        return start;
    }

    bool binaryElementSearch(vector<vector<int> >& matrix, int target, int row, int start, int end) {
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target == matrix[row][mid]) return true;
            if (target > matrix[row][mid])  start = mid + 1;
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