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
        __permute(num, 0, ret);
        return ret;
    }
private:
    void __permute(vector<int> num, int begin, vector<vector<int> >& ret) {
        int size = num.size();
        if (begin >= size-1)  { ret.push_back(num); return; }
        for (int i = begin; i < size; ++i) {
            swap(num[begin], num[i]);
            __permute(num, begin+1, ret);
            swap(num[begin], num[i]);
        }
    }

    void swap(int& a, int& b) {
        // if (&a == &b)   return; // ÓÐÐ§
        if (a == b) return;
        a = a^b;
        b = a^b;
        a = a^b;
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