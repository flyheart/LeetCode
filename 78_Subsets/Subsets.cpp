// Subsets.cpp

/**
 * Given a set of distinct integers, S, return all possible subsets.

 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,3], a solution is:

 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> e;
        int size = S.size();
        if (size <= 0)  return ret;
        for (int k = 0; k <= size; ++k) {
            __subsets(ret, S, e, 0, k);
        }

        return ret;
    }
private:
    void __subsets(vector<vector<int> >& ret, vector<int>& S, vector<int>& e, int start, int k) {
        if (0 == k) { ret.push_back(e); return; }
        int end = S.size();
        for (int i = start; i < end-k+1; ++i) {
            e.push_back(S[i]);
            __subsets(ret, S, e, i+1, k-1);
            e.pop_back();
        }
    }
};

int main(void) {
    Solution so;

    int A[] = {1, 2, 3, 4};
    vector<int> S(A, A+3);

    vector<vector<int> > ret = so.subsets(S);

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}