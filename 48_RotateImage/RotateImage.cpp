// RotateImage.cpp

/**
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
 */

// 仔细揣摩转换后各个元素之间的关系

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();

        for (int x = 0; x <= n-1-x; ++x) {
            for (int y = x; y < n-1-x; ++y) {
                int temp = matrix[x][y];
                matrix[x][y] = matrix[n-1-y][x];
                matrix[n-1-y][x] = matrix[n-1-x][n-1-y];
                matrix[n-1-x][n-1-y] = matrix[y][n-1-x];
                matrix[y][n-1-x] = temp;
            }
        }
    }
};

int main(void) {
    Solution so;
    vector<vector<int> > a;
    vector<int> b;
    vector<int> c;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    a.push_back(b);
    b.clear();
    b.push_back(5);
    b.push_back(6);
    b.push_back(7);
    b.push_back(8);
    a.push_back(b);
    b.clear();
    b.push_back(9);
    b.push_back(10);
    b.push_back(11);
    b.push_back(12);
    a.push_back(b);
    b.clear();
    b.push_back(13);
    b.push_back(14);
    b.push_back(15);
    b.push_back(16);
    a.push_back(b);

    so.rotate(a);

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}