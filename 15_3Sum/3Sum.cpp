/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        vector<int> solution;

        sort(num.begin(), num.end());
        int size = num.size();
        for (int i = 0; i < size; ++i) {
            // ÎªÁË±ÜÃâÖØ¸´
            if (i > 0 && num[i] == num[i - 1])   continue;

            int k = -num[i];
            int m = i + 1; int n = size - 1;
            while (m < n) {
                if (num[m] + num[n] > k)
                    --n;
                else if (num[m] + num[n] < k)
                    ++m;
                else {
                    solution.clear();
                    solution.push_back(num[i]);
                    solution.push_back(num[m]);
                    solution.push_back(num[n]);
                    ret.push_back(solution);
                    while (m+1 < n && num[m+1] == num[m])    ++m;
                    while (n-1 > m && num[n-1] == num[n]) --n;
                    ++m; 
                    --n;
                }
            }
        }

        return ret;
    }
};

int main(void) {
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);

    vector<int> v2;
    v2.push_back(-2);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(2);

    Solution so;
    vector<vector<int>> ret = so.threeSum(v2);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j)
            cout << ret[i][j] << '\t';
        cout << endl;
    }

    return 0;
}