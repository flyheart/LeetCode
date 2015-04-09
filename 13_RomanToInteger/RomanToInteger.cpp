/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string roman = "IVXLCDM";
        int number[] = {1, 5, 10, 50, 100, 500, 1000};
        int len = sizeof(number)/sizeof(*number);
        int size = s.size();
        int ret = 0;
        for (int i = 0; i < size;) {
            int index1 = roman.find(s[i]);
            int index2 = 0;
            if (i+1 < size)
                index2 = roman.find(s[i+1]);
            if (index1 < index2) {
                ret = ret + number[index2] - number[index1];
                i += 2;
            }
            else {
                ret += number[index1];
                i++;
            }
        }

        return ret;
    }
};

int main(void) {
    Solution so;
    cout << so.romanToInt("MMMCMXCIX") << endl;

    return 0;
}