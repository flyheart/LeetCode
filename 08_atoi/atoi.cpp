/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  
to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character,
takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains 
only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        int ret = 0;
        int len = str.size();
        int sign = 1;
        int i = 0;
        while (i < len) {
            if (' ' == str[i]) {
                ++i;
            }
            else
                break;
        }
        if ('-' == str[i]) {
            sign = -1;
            ++i;
        }
        else if ('+' == str[i]) {
            ++i;
        }
        ret *= sign;

        for (; i < len; ++i) {
            if (str[i] < '0' || str[i] > '9') break;
            ret = ret*10 + sign*(str[i] - '0');
            if (sign*ret % 10 != str[i] - '0') { // 整数越界
                if (-1 == sign) return INT_MIN;
                else                return INT_MAX;
            }
        }

        return ret;
    }
};

int main(void) {
    Solution so;
    cout << so.atoi("123") << endl;

    return 0;
}