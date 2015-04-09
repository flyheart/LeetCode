/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.

 * Empty cells are indicated by the character '.'.

 * You may assume that there will be only one unique solution.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(char board[][10]) {
        int rowFlags[9][9] = {0};
        int colFlags[9][9] = {0};
        int subFlags[9][9] = {0};

        int num;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('.' != board[i][j]) {
                    num = board[i][j] - '1';
                    rowFlags[i][num] = colFlags[num][j] = subFlags[i/3*3+j/3][num] = 1;
                }
            }
        }

        dfs(board, rowFlags, colFlags, subFlags, 0, 0);
    }
private:
    bool dfs(char board[][10], int (*rowFlags)[9], int (*colFlags)[9], int (*subFlags)[9], int row, int col) {
        int nextRow = 0, nextCol = 0;
        if (8 == col) {
            nextCol = 0;
            nextRow = row + 1;
        }
        else    { nextRow = row; nextCol = col + 1; }
        if (9 == row)   return true;

        if ('.' != board[row][col]) return dfs(board, rowFlags, colFlags, subFlags, nextRow, nextCol);

        int num;
        for (num = 0; num < 9; ++num) { // 9个值
            if (!rowFlags[row][num] && !colFlags[num][col] && !subFlags[row/3*3+col/3][num]) {
                rowFlags[row][num] = colFlags[num][col] = subFlags[row/3*3+col/3][num] = 1;
                board[row][col] = num+'1';
                if (!dfs(board, rowFlags, colFlags, subFlags, nextRow, nextCol)) {
            	    rowFlags[row][num] = colFlags[num][col] = subFlags[row/3*3+col/3][num] = 0;
            	    board[row][col] = '.';
            	}
            	else    return true;
            }
        }
        if (9 == num) { // 此时应该修改其上层节点
            return false;
        }
    }
};

int main(void) {
    Solution so;
    char board[][10] = {"..9748...","7........",".2.1.9...",
        "..7...24.", ".64.1.59.",".98...3..",
        "...8.3.2.","........6","...2759.."};
    so.solveSudoku(board);

    for (int i = 0; i < 9; ++i)
        cout << board[i] << endl;

    return 0;
}