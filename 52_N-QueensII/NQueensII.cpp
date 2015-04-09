// N-Queens.cpp

/**
 * Follow up for N-Queens problem.

 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string> > ret;
        int* flag = new int[n];
        memset(flag, 0, n*sizeof(int));
        int count = 0;
        dfs(count, flag, 0, n);

        return count;
    }
private:
    void dfs(int& count, int* flag, int row, int n) {
        if (row == n)   { ++count; return; }
        for (int i = 0; i < n; ++i) {
            if (isValid(flag, row, i)) {
                flag[row] = i;
                dfs(count, flag, row+1, n);
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

    cout << so.totalNQueens(4) << endl;

    return 0;
}