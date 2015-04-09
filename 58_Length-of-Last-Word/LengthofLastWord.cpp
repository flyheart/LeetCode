// LengthofLastWord.cpp

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 * return the length of last word in the string.

 * If the last word does not exist, return 0.

 * Note: A word is defined as a character sequence consists of non-space characters only.

 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

// ！！！！！！排除多个空格的情况！！！！！！

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        if (NULL == s)  return len;
        while (0 != *s) {
            if (' ' == *s) {
                while (' ' == *(s+1))   ++s;    // s指向最后一个空格
                if (0 == *(s+1))    return len;
                len = 0;    ++s;
            }
            else {
                ++len;  ++s;
            }
        }

        return len;
    }
};



int main(void) {
    Solution so;
    cout << so.lengthOfLastWord("Hello world ") << endl;
    cout << so.lengthOfLastWord("Hello world      ") << endl;

    return 0;
}