/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.  
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int sum = num[0] + num[1] + num[2];
        int size = num.size();
        for (int i = 0; i < size - 2; ++i) {
            int j = i + 1; int k = size - 1;
            int goal = target - num[i];
            while (j < k) {
                int s = num[j] + num[k];
                sum = fabs(target-sum) < fabs(target-s-num[i]) ? sum : s+num[i];
                if (s == goal)    return target;
                else if (s < goal)  ++j;
                else                    --k;
            }
        }

        return sum;
    }
private:
    int fabs(int i) { return i < 0 ? -i : i; }
};

int main(void) {
    vector<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    Solution so;

    cout << so.threeSumClosest(v, 1) << endl;
    return 0;
}