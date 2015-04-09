// SqrtX.cpp

/**
 * Implement int sqrt(int x).

 * Compute and return the square root of x.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (0 == x) return 0;
        return __sqrt(x, 1, x);
    }
private:
    int __sqrt(int x, int i, int j) {
        int mid = (i + j) / 2;

        if (mid == x/mid)   return mid;
        if (mid<x/mid && (mid+1)>x/(mid+1)) return mid;


        if (mid < x/mid)    return __sqrt(x, mid+1, j);
        return __sqrt(x, i, mid-1);
    }
};

int main(void) {
    Solution so;
    
    cout << so.sqrt(1) << endl;
    cout << so.sqrt(3) << endl;
    cout << so.sqrt(9) << endl;
    cout << so.sqrt(12) << endl;
    cout << so.sqrt(8192) << endl;

    return 0;
}