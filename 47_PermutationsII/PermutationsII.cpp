// PermutationsII.cpp

/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        permute(num, 0, ret);

        return ret;
    }
private:
    void permute(vector<int> num, int start, vector<vector<int> >& ret) {
        int size = num.size();
        if (start >= size)  { ret.push_back(num); return; }

        map<int, int> hash;
        for (int i = start; i < size; ++i) {
            if (hash.count(num[i]) > 0) continue;
            else    hash[num[i]] = i;
            swap(num[start], num[i]);
            permute(num, start+1, ret);
            swap(num[i], num[start]);
        }
    }

    void swap(int& a, int& b) {
        if (a == b) return;
        a = a^b;
        b = a^b;
        a = a^b;
    }
};

int main(void) {
    Solution so;

    vector<int> num;
    num.push_back(0);
    num.push_back(1);
    num.push_back(0);
    num.push_back(0);
    num.push_back(9);

    vector<vector<int> > ret = so.permuteUnique(num);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}