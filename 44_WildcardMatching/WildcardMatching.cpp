// WildcardMatching.cpp
/**
 * Implement wildcard pattern matching with support for '?' and '*'.

 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).

 * The matching should cover the entire input string (not partial).

 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)

 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 */

#include <iostream>
using namespace std;

/*将此题误与第10题正则表达式看成了一致。
class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        if (NULL==s || NULL==p) return NULL;
        // if (0==*p && 0==*s) return true;
        // else if (0==*p || 0==*s)    return false;
        if (0 == *p)    return 0==*s;

        if ('*' == *(p+1)) {
            // if (isMatch(s, p+2))    return true;
            while ( 0!=*s && (*s==*p || '.'==*p)) {
            // while ( (0!=*s && *s==*p) || '.'==*p) {
                if (isMatch(s, p+2))  return true;
                ++s;
            }
            return isMatch(s, p+2);
        }
        if (0!=*s && ('.'==*p || *s==*p))
            return isMatch(s+1, p+1);
        else    return false;
    }
};

int main(void) {
    Solution so;
    // cout << so.isMatch("aab", "c*b") << endl;
    // cout << so.isMatch("aa", ".*") << endl;
    // cout << so.isMatch("a", ".*..a*") << endl;  // false
    cout << so.isMatch("", ".a*") << endl;  // false
    // cout << so.isMatch("a", "ab*") << endl;

    return 0;
}
*/

class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        if (NULL==s || NULL==p) return false;
        if (0 == *p) return 0==*s;

        if ('*' == *p) {
            while ('*' == *p)   ++p;
            while(0 != *s) {
                if (isMatch(s, p))    return true;
                s++;
            }
            return isMatch(s, p);
        }

        if ((0!=*s) && (*s==*p || '.'==*p)) return isMatch(s+1, p+1);
        else    return false;
    }
};

int main(void) {
    Solution so;
    cout << so.isMatch("aab", "c*b") << endl;
    cout << so.isMatch("aa", ".*") << endl;
    cout << so.isMatch("a", ".*..a*") << endl;  // false
    cout << so.isMatch("", ".a*") << endl;  // false
    cout << so.isMatch("a", "ab*") << endl;
    cout << so.isMatch("aabc", "a*ab*") << endl;
    cout << so.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;

    return 0;
}