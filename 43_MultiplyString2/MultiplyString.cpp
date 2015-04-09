// MultiplyStrings.cpp
/**
 * Given two numbers represented as strings, return multiplication of the numbers as a string.

 * Note: The numbers can be arbitrarily large and are non-negative.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int s1 = num1.size();
        int s2 = num2.size();
        vector<int> ret(s1+s2);
        for (int i = s2-1; i >= 0; --i) {
            int carry = 0;
            int multi = 0;
            int j = s1 - 1;
            for (; j >= 0; --j) {
                multi = ret[i+j+1] + (num1[j]-'0')*(num2[i]-'0') + carry;
                carry = multi / 10;
                ret[i+j+1] = multi % 10;
            }
            ret[i+j+1] += carry;
        }

        string str="";
        int size = ret.size();
        int i = 0;
        for (; i < size-1; ++i) {
            if (0 != ret[i])    break;
        }
        for (int j = i; j < size; ++j)
            str.append(1, ret[j]+'0');

        return str;

    }
};

int main(void) {
    Solution so;
    
    cout << so.multiply("0", "0") << endl;
    cout << so.multiply("9", "9") << endl;
    cout << so.multiply("123", "2") << endl;
    cout << so.multiply("2", "123") << endl;
    cout << so.multiply("123456789", "987654321") << endl;

    return 0;
}