/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
/*
思路：
两边设一个指针，然后计算area，如果height[i] <= height[j]，那么i++，因为在这里height[i]是瓶颈，j往里移只会减少面积，不会再增加area。

这是一个贪心的策略，每次取两边围栏最矮的一个推进，希望获取更多的水。

一个不严格的证明：

当height[i] <= height[j]时，为什么是i++，而不是j++来获取可能更多的水？

假设j' > j，之所以j'往左移，是因为存在height[i'] > height[j'] (i’ <= i), 而那时area' = (j' - i') * min(height[i'], height[j'])，

因为height[j'] == min(height[i'], height[j'])，所以area' = (j' - i') * height[j']。

而i 和 j'构成的面积area = (j' - i) * min(height[i], height[j'])。

area' >= area，所以j不需要往右移。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        int max = 0;
        int area = 0;
        int i = 0, j = size - 1;
        while (i < j) {
            area = (j - i) * min(height[i], height[j]);
            max = max < area ? area : max;
            if (height[i] < height[j])  ++i;
            else                               --j;
        }

        return max;
    }
};

int main(void) {
    Solution so;
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    cout << so.maxArea(A) << endl;

    return 0;
}