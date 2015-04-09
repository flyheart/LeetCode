// Permutations.cpp

/**
 * Given a collection of numbers, return all possible permutations.

 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> res;
        permute(num, res, ret);
        return ret;
    }
private:
    void permute(vector<int>& num, vector<int>& res, vector<vector<int> >& ret) {
        int size = num.size();
        if (0 == size)  { ret.push_back(res); return; }
        for (int i = 0; i < size; ++i) {
            res.push_back(num[i]);
            vector<int> remain = num;
            remain.erase(remain.begin()+i);
            permute(remain, res, ret);
            res.pop_back();
        }
    }
};

int main(void) {
    Solution so;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    vector<vector<int> > ret = so.permute(num);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
}