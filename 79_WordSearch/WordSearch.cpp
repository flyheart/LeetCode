// WordSearch.cpp

/**
 * Given a 2D board and a word, find if the word exists in the grid.

 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells 
 * are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

 * For example,
 * Given board =

 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if (0 == board.size())  return false;
        return dfs(board, word, 0, 0, 0);
    }
private:
    struct Point {
        int x;
        int y;
        Point(int a, int b) : x(a), y(b) {}
    };
    bool dfs(vector<vector<char> >& board, string word, int i, int j, int k) {
        if (k == word.size())   return true;
        if (board[i][j] == word[k]) {
            if (k == word.size()-1) return true;    // 处理board只有一个元素的情况
            vector<Point> neighbors = findNeighbors(board, i, j);
            for (int m = 0; m < neighbors.size(); ++m) {
                char t = board[i][j];
                board[i][j] = 0;
                // if (dfs(board, word, neighbors[m].x, neighbors[m].y, k+1))  return true;    // 成功时变不再恢复board中的数值，做法不妥
                bool ret = dfs(board, word, neighbors[m].x, neighbors[m].y, k+1);
                board[i][j] = t;
                if (true == ret)    return ret;
            }
        }
        if (0 == k) {
            if (j == board[i].size()-1) {
                j = 0; ++i;
            }
            else    ++j;
            if (i == board.size())  return false;
            return dfs(board, word, i, j, k);
        }
        return false;
    }
    vector<Point> findNeighbors(vector<vector<char> >& board, int i, int j) {
        vector<Point> vc;
        if (i > 0)  vc.push_back(Point(i-1, j));
        if (i < board.size()-1)  vc.push_back(Point(i+1, j));
        if (j > 0)  vc.push_back(Point(i, j-1));
        if (j < board[i].size()-1) vc.push_back(Point(i, j+1));

        return vc;
    }
};

int main(void) {
    Solution so;

    char A1[4] = {'A', 'B', 'C', 'E'};
    char A2[4] = {'S', 'F', 'C', 'S'};
    char A3[4] = {'A', 'D', 'E', 'E'};

    vector<char> v1(A1, A1+4);
    vector<char> v2(A2, A2+4);
    vector<char> v3(A3, A3+4);
    vector<vector<char> > board;
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);

    vector<vector<char> > board2;
    vector<char> v4(1, 'A');
    board2.push_back(v4);
    cout << so.exist(board2, "A") << endl;
    cout << so.exist(board, "S") << endl;
    cout << so.exist(board, "SEE") << endl;
    cout << so.exist(board, "ABCCED") << endl;
    cout << so.exist(board, "ABCB") << endl;

    return 0;
}