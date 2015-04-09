// N-Queens.cpp

/**
 * The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens 
 * attack each other.

 * Given an integer n, return all distinct solutions to the n-queens puzzle.

 * Each solution contains a distinct board configuration of the n-queens' placement, 
 * where 'Q' and '.' both indicate a queen and an empty space respectively.

 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:

 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],

 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        int* flag = new int[n];
        memset(flag, 0, n*sizeof(int));
        string str(n, '.');
        vector<string> vs(n, str);

        dfs(ret, vs, flag, 0, n);

        return ret;
    }
private:
    void dfs(vector<vector<string> >& queens, vector<string>& str, int* flag, int row, int n) {
        if (row == n)   { queens.push_back(str); return; }
        for (int i = 0; i < n; ++i) {
            if (isValid(flag, row, i)) {
                flag[row] = i;
                str[row][i] = 'Q';
                dfs(queens, str, flag, row+1, n);
                str[row][i] = '.';
            }
        }
    }
    bool isValid(int* flag, int x, int y) {
        for (int i = 0; i < x; ++i) {
            if (flag[i]==y || abs(x-i)==abs(y - flag[i]))
                return false;
        }
        return true;
    }
};

int main(void) {
    Solution so;
    vector<vector<string> > ret = so.solveNQueens(4);

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}