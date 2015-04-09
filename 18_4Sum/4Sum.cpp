/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        int size = num.size();
        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && num[i-1] == num[i]) continue;
            int t1 = target - num[i];
            for (int j = i + 1; j < size - 2; ++j) {
                if (i != j - 1 && num[j-1] == num[j]) continue;
                int t2 = t1 - num[j];
                int m = j + 1; int n = size - 1;
                while (m < n) {
                    if (num[m] +num[n] > t2) --n;
                    else if (num[m] + num[n] < t2) ++m;
                    else {
                        vector<int> sum;
                        sum.push_back(num[i]);
                        sum.push_back(num[j]);
                        sum.push_back(num[m]);
                        sum.push_back(num[n]);
                        ret.push_back(sum);
                        while (m < n && num[m+1] == num[m]) ++m;
                        while (m < n && num[n-1] == num[n]) --n;
                        ++m;
                        --n;
                    }
                }
            }
        }

        return ret;
    }
};

int main(void) {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(-1);
    v.push_back(0);
    v.push_back(-2);
    v.push_back(2);

    vector<int> v2;
    v2.push_back(-2);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(2);

    Solution so;
    vector<vector<int>> ret = so.fourSum(v, 0);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << '\t';
        cout << endl;
    }
    
    return 0;
}