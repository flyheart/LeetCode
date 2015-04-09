/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        char symbol[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};    // 罗马数字似乎是5进制
        int index = 0;  // 指示当前所对应的罗马数字的第几位
        int divisor = 1000;
        while (divisor != 0) {
            int flag = num / divisor;
            if (9 == flag) {
                roman = roman + symbol[index] + symbol[index - 2];
            }
            else if (4 == flag) {
                roman = roman + symbol[index] + symbol[index - 1];
            }
            else {
                if (flag > 4) {
                    flag -= 5;
                    roman += symbol[index - 1];
                }
                for (int i = 0; i < flag; ++i)
                    roman += symbol[index];
            }

            index += 2;
            num -= num / divisor * divisor;
            divisor /= 10;
        }

        return roman;
    }
};


int  main(void) {
    Solution so;
    cout << so.intToRoman(2000) << endl;

    return 0;
}