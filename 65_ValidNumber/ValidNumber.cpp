// ValidNumber.cpp

/**
 * Validate if a given string is numeric.

 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front
 * before implementing one.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool num = false;
        bool e = false;
        bool dot = false;
        bool num_after_dot = false;
        bool num_after_e = false;

        int size = s.size();
        if (0 == size)  return false;
        int start = 0, end = size-1;
        while (start<=end && ' '==s[start]) ++start;
        while (start<=end && ' '==s[end])   --end;

        if (start>end) return false;
        if ('+'==s[start] || '-'==s[start]) ++start;

        for (int i = start; i <= end; ++i) {
            if (s[i]>='0' && s[i]<='9') {
                num = !dot ? true : num;
                num_after_dot = dot;
                num_after_e = e;
                continue;
            }
            if (!dot && '.'==s[i])  { 
                if(e==true)   return false;
                dot = true; continue; 
            }
            if ((num||num_after_dot) && !e && 'e' == s[i] && i<end)  {
                e = true;
                if ('+'==s[i+1] || '-'==s[i+1]) ++i;
                continue;
            }

            return false;
        }

        return (num||num_after_dot)&&!(e^num_after_e);
    }
};

int main(void) {
    Solution so;

    cout << so.isNumber("005047e+") << false << endl;
    cout << so.isNumber("005047e+6") << true << endl;
    cout << so.isNumber("+") << false << endl;
    cout << so.isNumber("0.2") << true << endl;
    cout << so.isNumber("02") << true << endl;
    cout << so.isNumber(".2e81") << true << endl;
    cout << so.isNumber(".") << false << endl;
    cout << so.isNumber(".3") << true << endl;
    cout << so.isNumber("1e.") << false << endl;
    cout << so.isNumber("e10") << false << endl; // false
    cout << so.isNumber("1 ") << true << endl; // true
    cout << so.isNumber(" 1") << true << endl; // true
    cout << so.isNumber(" ") << false << endl; // false
    cout << so.isNumber("       ") << false << endl; // false
    cout << so.isNumber("3.") << true << endl; // true
    cout << so.isNumber("1.2e10") << true << endl;
    cout << so.isNumber("1.2e.0") << false << endl;

    return 0;
}