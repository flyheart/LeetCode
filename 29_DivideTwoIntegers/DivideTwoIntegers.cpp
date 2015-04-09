/**
 * Divide two integers without using multiplication, division and mod operator.

 * If it is overflow, return MAX_INT.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == divisor)   return INT_MAX;
        long long divid = dividend, divis = divisor;
        divid = divid < 0 ? -divid : divid;
        divis = divis < 0 ? -divis : divis;

        // 使用unsigned int已足矣涵盖范围，两个整数相除，res最大值为2147483648 > INT_MAX,
        // 故returned INT_MAXunsigned int res = 0;   
        long long res = 0;
        while (divid >= divis) {
            long long div = divis;
            int i;
            for (i = 0; div <= divid; ++i) {
                div <<= 1;
            }
            res += 1<<(i-1);
            if (res < 0)    res = -res; // 1<<31 == -2147483648
            divid -= divis<<(i-1);
        }

        // res = (dividend^divisor) > 0 ? res : -res;
        if ((dividend^divisor) < 0)   {
            res = -res;
        }
        if (res > INT_MAX)  return INT_MAX;
        return res;
    }
};

int main(void) {
    Solution so;
    cout << so.divide(-1, 1) << endl;
    cout << so.divide(-2147483648, -1) << endl;
    cout << so.divide(-2147483648, 1) << endl;
    int a = INT_MAX+1;
    cout << a << '\t' << -a << endl;

    return 0;
}

