/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = 1;   // 标记正负数
        if (x < 0) {
            x = -x;
            sign = -1;
        }
        int ret = 0;
        while (x != 0) {
            int remainder = x % 10;
            x = x / 10;
            ret = 10*ret + remainder;
            // 判断ret是否越界!!!!!!如果是则返回0
            if (ret % 10 != remainder)
                return 0;
        }

        return sign * ret;
    }
};

int main(void) {
    Solution so;
    cout << so.reverse(1534236469) << endl;
    cout << so.reverse(-123) << endl;

    return 0;
}