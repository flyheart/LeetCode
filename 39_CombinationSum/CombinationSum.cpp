/**
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 * The same repeated number may be chosen from C unlimited number of times.

 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        int size = candidates.size();
        vector<int> cur;
        combinationKSum(candidates, target, 0, cur, ret);

        return ret;
    }
private:
    void combinationKSum(vector<int>& candidates, int target, int start, vector<int>& cur, vector<vector<int> >& ret) {
        int size = candidates.size();
        if (start>=size || candidates[start]>target)  return;

        if (candidates[start] < target) {
            cur.push_back(candidates[start]);
            combinationKSum(candidates, target-candidates[start], start, cur, ret);
            while (start<size-1 && candidates[start+1]==candidates[start])  ++start;
            cur.pop_back();
            // cur.push_back(candidates[start+1]);
            combinationKSum(candidates, target, start+1, cur, ret);
        }
        else {
            cur.push_back(candidates[start]);
            ret.push_back(cur);
            cur.pop_back();
            return;
        }
    }
    /**
     * vector<int> twoSumTarget(vector<int>& candidates, int target, int start, int end) {
     *     vector<int> ret;
     *     if (candidates[start]>= target || candidates[end] <= target)  return ret;
     *     while(start < end) {
     *         int sum = candidates[start] + candidates[end];
     *         if (sum > target)   --end;
     *         else if (sum < target)  ++start;
     *         else {
     *             ret.push_back(candidates[start]);
     *             ret.push_back(candidates[end]);
     *             while (start<end && candidates[start+1]==candidates[start])  ++start;
     *             while (start<end && candidates[end-1]==candidates[end])  --end;
     *         }
     *     }

     *     return ret;
     * }
     */
};

int main(void) {
    Solution so;
    vector<int> v;
    v.push_back(8);
    v.push_back(7);
    v.push_back(4);
    v.push_back(3);

    vector<vector<int> > ret = so.combinationSum(v, 11);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}