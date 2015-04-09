/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        if (NULL == s || NULL == p) return false;

        if (0 == *p)    return (*s == 0);

        if (*(p+1) == '*') {
            while((*s != 0 && *p=='.') || *p==*s) { // 由于*(p+1)=='*',因此*p!=0,此式等价于while(0!=*s && (*s==*p || '.'==*p))
                if (isMatch(s, p+2))  return true;
                s++;
            }

            return isMatch(s, p+2);
        }
        else {
            if ((*s != 0 && *p=='.') || *p==*s)
                return isMatch(s+1, p+1);
            else
                return false;
        }

    }
};

int main(void) {
    Solution so;
    char* s = "abbcbbcd";
    char* p = "a*cd";
    int i = so.isMatch(s, p);
    // cout << so.isMatch(s, p) << endl;
    // cout << so.isMatch("aa", "a*") << endl;
    // cout << so.isMatch("cc", "a*cc") << endl;
    // cout << so.isMatch("aa", "*") << endl;
    // cout << so.isMatch("a", ".*..a*") << endl;
    // cout << so.isMatch("a", "a.*") << endl;
    cout << so.isMatch("", ".a*") << endl;
}