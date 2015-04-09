/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
/*
˼·��
������һ��ָ�룬Ȼ�����area�����height[i] <= height[j]����ôi++����Ϊ������height[i]��ƿ����j������ֻ��������������������area��

����һ��̰�ĵĲ��ԣ�ÿ��ȡ����Χ�����һ���ƽ���ϣ����ȡ�����ˮ��

һ�����ϸ��֤����

��height[i] <= height[j]ʱ��Ϊʲô��i++��������j++����ȡ���ܸ����ˮ��

����j' > j��֮����j'�����ƣ�����Ϊ����height[i'] > height[j'] (i�� <= i), ����ʱarea' = (j' - i') * min(height[i'], height[j'])��

��Ϊheight[j'] == min(height[i'], height[j'])������area' = (j' - i') * height[j']��

��i �� j'���ɵ����area = (j' - i) * min(height[i], height[j'])��

area' >= area������j����Ҫ�����ơ�
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