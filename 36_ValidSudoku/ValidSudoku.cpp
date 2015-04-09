/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules (http://sudoku.com.au/TheRules.aspx).
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * A partially filled sudoku which is valid.

 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

// 为什么可以这么粗心!!!!!!!!!!!!!!!!!!!,数组访问越界

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int row = board.size();
        if (0 == row)   return false;
        int col = board[0].size();
        if (0 == col)   return false;

        int rowFlag[9][9] = {0};
        int colFlag[9][9] = {0};
        int subFlag[9][9] = {0};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if ('.' != board[i][j]) {
                    int num = board[i][j] - '0' - 1;
                    int m = i/3*3 + num/3, n = j/3*3 + num%3;
                    if (rowFlag[i][num] || colFlag[num][j] || subFlag[m][n])
                        return false;
                    rowFlag[i][num] = colFlag[num][j] = subFlag[m][n] = 1;
                }
            }
        }

        return true;
    }
};

int main(void) {

    return 0;
}