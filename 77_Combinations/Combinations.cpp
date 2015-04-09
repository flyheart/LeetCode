// Combinations.cpp

/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 * For example,
 * If n = 4 and k = 2, a solution is:

 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        if (n<k || k<=0)  return ret;
        vector<int> e;
        __combine(ret, e, 1, n, k);

        return ret;
    }
private:
    void __combine(vector<vector<int> >& ret, vector<int>& e, int start, int end, int k) {
        if (0 == k) {
            ret.push_back(e);   return;
        }
        for (int j = start; j <= end-k+1; ++j) {
            e.push_back(j);
            __combine(ret, e, j+1, end, k-1);
            e.pop_back();
        }
    }
};

int main(void) {
    Solution so;

    vector<vector<int> > ret = so.combine(4, 3);

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}