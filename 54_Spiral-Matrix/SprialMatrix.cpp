// SprialMatrix.cpp

/**
 * Given a matrix of m x n elements (m rows, n rcolumns), return all elements of the matrix in spiral order.

 * For example,
 * Given the following matrix:

 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int start = 0;
        int end = n - 1;
        vector<int> ret;
        if (0 == n) return ret;
        int lcol = 0;
        int rcol = matrix[0].size() - 1;

        while (start <= end) {
            for (int i = lcol; i <= rcol; ++i) {
                ret.push_back(matrix[start][i]);
            }
            // ++start;
            if (++start > end)    break;
            for (int j = start; /*start<=end && */j<=end; ++j) {
                ret.push_back(matrix[j][rcol]);
            }
            if (--rcol < lcol)  break;
            for (int k = rcol; k >= lcol; --k) {
                ret.push_back(matrix[end][k]);
            }
            --end;
            

            if (start > end)    break;
            for (int i = end; i >= start; --i) {
                ret.push_back(matrix[i][lcol]);
            }
            if (++lcol > rcol)    break;
        }

        return ret;
    }
};

int main(void) {
    vector<vector<int> > input;
    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    input.push_back(in);
    in.clear();

    in.push_back(4);
    in.push_back(5);
    in.push_back(6);
    input.push_back(in);
    in.clear();

    in.push_back(7);
    in.push_back(8);
    in.push_back(9);
    input.push_back(in);
    in.clear();

    in.push_back(10);
    in.push_back(11);
    in.push_back(12);
    input.push_back(in);
    in.clear();

    in.push_back(13);
    in.push_back(14);
    in.push_back(15);
    input.push_back(in);
    in.clear();

    vector<vector<int> > input2;
    vector<int> in2;
    in2.push_back(1);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(2);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(3);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(4);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(5);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(6);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(7);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(8);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(9);
    input2.push_back(in2);
    in2.clear();

    in2.push_back(10);
    input2.push_back(in2);
    in2.clear();


    Solution so;
    vector<int> output = so.spiralOrder(input2);
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << ' ';
    }
    cout << endl;
    
    return 0;
}