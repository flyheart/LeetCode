/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (1==nRows)
            return s;
        int len = s.size();
        string zigzag;
        for (int i = 0; i < nRows; ++i) {
            int d = 2 * (nRows - i) - 2;
            if (i < len) {
                zigzag += s[i];
            }
            int d1 = d;
            int d2 = 2 * i;
            int index = i;
            while (true) {
                if (d1 != 0) {
                    index += d1;
                    if (index < len)
                        zigzag += s[index];
                    else
                        break;
                }
                if (d2 != 0) {
                    index += d2;
                    if (index < len)
                        zigzag += s[index];
                    else
                        break;
                }
                if (d1==0 && d2 == 0)
                    break;
            }
        }

        return zigzag;
    }
};

int main(void) {
    Solution so;
    cout << so.convert("PAYPALISHIRING", 3) << endl;
}