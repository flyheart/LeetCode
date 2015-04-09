// powx-n.cpp

/**
 * Implement pow(x, n).
 */

#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double ret = 1.0;
        int sign = n >= 0 ? 1 : -1;
        n = n >= 0 ? n : -n;
        while (n >= 1) {
            long long e = 2;
            double subret = x;
            while (e <= n) {
                subret *= subret;
                e <<= 1;
            }
            n -= e>>1;
            ret *= subret;
        }

        if (-1 == sign) return 1/ret;
        else    return ret;
    }
};

int main(void) {
    Solution so;

    cout << so.pow(3, 0) << endl;
    cout << so.pow(3, 1) << endl;
    cout << so.pow(3, 2) << endl;
    cout << so.pow(3, 6) << endl;
    cout << so.pow(3, -1) << endl;
    cout << so.pow(3, -2) << endl;
    cout << so.pow(3, -6) << endl;

    return 0;
}