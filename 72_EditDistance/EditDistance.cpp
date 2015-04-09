// EditDistance.cpp

/**
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
 * (each operation is counted as 1 step.)

 * You have the following 3 operations permitted on a word:

 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        word1.insert(word1.begin(), '#');
        word2.insert(word2.begin(), '#');

        int M = word1.size();
        int N = word2.size();

        int** D = new int*[M];
        for (int k = 0; k < M; ++k) {
            D[k] = new int[N];
            memset(D[k], 0, N*sizeof(int));
        }
        for (int i = 0; i < M; ++i) D[i][0] = i;
        for (int j = 0; j < N; ++j) D[0][j] = j;

        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                int d1 = D[i-1][j] + 1; // insert item
                int d2 = D[i][j-1] + 1; // delete item
                // replace item
                int d3 = D[i-1][j-1];
                d3 = word1[i]==word2[j] ? d3 : d3+1;

                D[i][j] = min(d1, d2, d3);
            }
        }
        int ret = D[M-1][N-1];
        for (int i = 0; i < M; ++i)
            delete []D[i];
        delete []D;

        return ret;
    }

private:
    int min(int a, int b, int c) {
        if (a <= b) {
            if (a <= c) return a;
            return c;
        }
        else {
            if (b <= c)    return b;
            return c;
        }
    }
};

int main(void) {
    Solution so;

    cout << so.minDistance("abc", "acb") << endl;

    return 0;
}