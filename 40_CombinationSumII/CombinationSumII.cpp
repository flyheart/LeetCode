// CombinationSumII.cpp
/**
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 * Each number in C may only be used once in the combination.

 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        int size = num.size();
        vector<int> cur;
        combinationKSum(num, target, 0, cur, ret);

        return ret;
    }
private:
    void combinationKSum(vector<int>& num, int target, int start, vector<int>& cur, vector<vector<int> >& ret) {
        int size = num.size();
        if (start>=size || num[start]>target)  return;

        if (num[start] < target) {
            cur.push_back(num[start]);
            combinationKSum(num, target-num[start], start+1, cur, ret);
            while (start<size-1 && num[start+1]==num[start])  ++start;
            cur.pop_back();
            // cur.push_back(num[start+1]);
            combinationKSum(num, target, start+1, cur, ret);
        }
        else {
            cur.push_back(num[start]);
            ret.push_back(cur);
            cur.pop_back();
            return;
        }
    }
};

int main(void) {
    Solution so;
    vector<int> v;
    v.push_back(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(6);
    v.push_back(1);
    v.push_back(5);

    vector<vector<int> > ret = so.combinationSum2(v, 8);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}