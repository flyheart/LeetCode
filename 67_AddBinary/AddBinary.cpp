// AddBinary.cpp

/**
 * Given two binary strings, return their sum (also a binary string).

 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int size1 = a.size();
        int size2 = b.size();
        if (0 == size1) return b;
        if (0 == size2) return a;
        int size = size1 > size2 ? size1 : size2;
        string c(size+1, 0);

        int carry = 0;
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            if (i<size1 && i<size2) {
                sum = a[size1-1-i]- '0' + b[size2-1-i]- '0' + carry;
            }
            else if (i < size1) {
                sum = a[size1-1-i]-'0' + carry;
            }
            else {
                sum = b[size2-1-i] -'0' + carry;
            }
            carry = sum / 2;
            c[size-i] = sum % 2 +'0';
        }
        c[0] = carry+'0';
        int i = 0;
        if ('0' == c[0]) ++i;

        return c.substr(i, string::npos);
    }
};

int main(void) {
    Solution so;

    cout << so.addBinary("1111", "1") << endl;
    cout << so.addBinary("0", "0") << endl;

    return 0;
}